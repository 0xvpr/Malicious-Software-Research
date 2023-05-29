global          entry
global          NtWriteFile
global          KrnlGetStdHandle

section         .text
value:
    dq          -11
isb:
    dd          0
    dq          0
str:
    db          "Syscall gang",0xA,0
entry:
    push        rbp
    mov         rbp, rsp
    sub         rsp, 0x78

    mov         ecx, dword [rel value]
    call        KrnlGetStdHandle
    push        rax

    xor         eax, eax
    mov         qword [rsp + 0x48], rax
    mov         qword [rsp + 0x40], rax
    mov         qword [rsp + 0x38], entry - str     ; entry-str = strlen
    lea         rax, [rel str]
    mov         qword [rsp + 0x30], rax
    lea         rax, [rel isb]
    mov         qword [rsp + 0x28], rax
    xor         r9d, r9d
    xor         r8d, r8d
    xor         edx, edx
    pop         rcx
    call        NtWriteFile

    xor         eax, eax
    add         rsp, 0x78
    pop         rbp
    ret

NtWriteFile:
    mov         r10, rcx 
    mov         eax, 0x8                            ; 0x8 is the syscall for NtWriteFile
    syscall
    ret

KrnlGetStdHandle:
    mov         rax, [gs:0x60]                      ; Loading in kernel32
    mov         rcx, [rax + 0x20]                   
    mov         rax, [rcx + 0x28]
    ret
