/**
 * @file      main.c
 * @author    vpr
 * @brief     -
 * @version   0.1
 * @date      2021-08-15
 * 
 * @copyright Copyright (c) 2021
 */

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG

int main()
{
    unsigned char* payload = {
        0x90,    // nop
        0x90,    // nop
        0xCC,    // int3
        0xC3     // ret
    };

    size_t size = 4;

    // Allocate memory for payload
    void* exec_mem = VirtualAlloc(0, size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

#ifdef DEBUG
    printf("Payload address : 0x%-16p\n", (void *)payload);
    printf("Memory address : 0x%-16p\n", (void *)exec_mem);
#endif

    // Copy payload to new buffer
    RtlMoveMemory(exec_mem, payload, size);

    // Make buffer executable
    BOOL success = VirtualProtect(exec_mem, size, PAGE_EXECUTE_READ, &old_protect);

    printf("\nContinue...\n");
    getchar();

    if (!success)
    {
        HANDLE hThread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE), exec_mem, 0, 0, 0);
        WaitForSingleObject(hThread, -1);
    }

    return TRUE;
}