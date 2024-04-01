global          entry

section         .rodata
isb:
    dd          0
    dq          0
str:
    db          "Syscall gang",0xA,0

section         .text
entry:
    push        rbp
    mov         rbp, rsp
    sub         rsp, 0x48
    mov         rcx, [gs:0x60]                      ; PEB
    cmp         byte [rcx + 0x3], 1
    je          exit
prologue:
    xor         eax, eax
    mov         qword [rsp + 0x40], rax
    mov         qword [rsp + 0x38], rax
    mov         qword [rsp + 0x30], 13              ; strlen(str) == 13
    lea         rax, qword [rel str]
    mov         qword [rsp + 0x28], rax
    lea         rax, qword [rel isb]
    mov         qword [rsp + 0x20], rax
    xor         r9d, r9d
    xor         r8d, r8d
    xor         edx, edx

    mov         rcx, [rcx + 0x20]                   ; PEB loader
    mov         rcx, [rcx + 0x28]                   ; kernel32
    call        NtWriteFile
exit:
    xor         eax, eax
    add         rsp, 0x48
    pop         rbp
    ret
NtWriteFile:
    mov         r10, rcx
    mov         eax, 0x8                            ; 0x8 is the syscall for NtWriteFile
    syscall
    ret
