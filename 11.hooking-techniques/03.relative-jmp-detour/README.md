# Relative Jump Detour (C++ lambda)
This example uses the intel-x86_64 instruction set to perform a relative jump  
to a given function. In this case, we are detouring the target to a lambda  
function that exists on the stack.

### How it works
The main idea behind this is that we move the address of the source  
hook function into a 32 bit register and jump to it (if it fits).

```nasm
jmp $ + relative_32bit_address

;Disassembly:
;0:  E9  78 56 34 12    jmp $ + 0x12345673
```

We achieve this using a packed struct
```c
typedef struct __attribute__((packed)) _AsmBlock {
    uint8_t   jmp_rax;
    int32_t   relative_address;
} AsmBlock;
```

## Build (Parent Repository WSL2+Docker Environment Recommended)
`make`
