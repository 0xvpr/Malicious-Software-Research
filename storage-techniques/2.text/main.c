#include <windows.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    void* exec_mem;
    BOOL rv;
    HANDLE th;
    DWORD old_protect;

    unsigned char payload[4] = {
        0x90,  // nop
        0x90,  // nop
        0xCC,  // int3
        0xC3   // ret
    };
    size_t size = 4;

    // Allocate a memory buffer for payload
    exec_mem = VirtualAlloc(NULL, size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

    printf("Payload address: 0x%-16p\n", (void *)payload);
    printf("Executable memory address: 0x%-16p\n", (void *)exec_mem);

    // Move payload into newly allocated memory
    RtlMoveMemory(exec_mem, payload, size);

    // Change the permissions of the memory to make it executable
    rv = VirtualProtect(exec_mem, size, PAGE_EXECUTE_READ, &old_protect);

    system("pause");

    // If successful, start a thread using the payload, then wait for it to exit.
    if (rv)
    {
        th = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)exec_mem, NULL, 0, NULL);
        WaitForSingleObject(th, INFINITE); // optional
    }

    return 0;
}
