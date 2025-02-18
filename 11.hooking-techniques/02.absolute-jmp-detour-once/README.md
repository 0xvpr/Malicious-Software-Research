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

Finally the instance pointer is set and called during the hook
```c
// Hook constructor
// (...)
{
    hook_ptr = this; // static instance pointer variable
}
// int main(...)
{
    hook.detour([](char*, int* x) -> void {
        puts("Detour\n");
        *x = 42069;

        Hook::hook_ptr->restore();
    });
}
```

## Build (Parent Repository WSL2+Docker Environment Recommended)
`make`
