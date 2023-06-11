# Absolute Jump Detour Once (C++ lambda)
This example uses the intel-x86_64 instruction set to perform an absolute jump  
to a given function. In this case, we are detouring the target to a lambda  
function that exists on the stack and only executes onces, before restoring  
the original function.

This example is just a POC meandering, **it is completely inefficient and utter  
garbage**

### How it works
The main idea behind this is that we move the absolute address of the source  
hook function into rax and jump to it.

```nasm
mov rax, [ absolute_address ]
jmp rax

;Disassembly:
;0:  48 b8 ff ff ff ff ff    movabs rax,0x7fffffffffffffff
;7:  ff ff 7f
;a:  ff e0                   jmp    rax
```

We achieve this using a packed struct
```c
typedef struct __attribute__((packed)) _AsmBlock {
    uint16_t   mov_rax;
    void*      address;
    uint16_t   jmp_rax;
} AsmBlock;
```

Finally the exception handler is set (awful technique but it works)
```c
// Hook constructor
// (...)
{
    pHook = this; // static class variable
    SetUnhandledExceptionFilter( [](EXCEPTION_POINTERS* exceptionInfo) -> LONG WINAPI {
        if (exceptionInfo->ExceptionRecord->ExceptionCode == EXCEPTION_BREAKPOINT) {
            pHook->swap_zero_byte();
            pHook->restore();

            return EXCEPTION_CONTINUE_EXECUTION;
        };

        return EXCEPTION_CONTINUE_SEARCH;
    });
}
```

## Build (Parent Repository WSL2+Docker Environment Recommended)
`make`
