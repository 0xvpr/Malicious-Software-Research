extern write_hello              ; Import c function

segment .text
    global alignstack

alignstack:
    push    rdi                 ; Backup rdi since we will be using this as our main register
    mov     rdi, rsp            ; Save the stack pointer to rdi
    and     rsp, byte -0x10     ; Align the stack with 16 bytes
    sub     rsp, byte +0x20     ; Allocate space for the write_hello function
    call    write_hello         ; Call to write_hello
    mov     rsp, rdi            ; Restore stack pointer
    pop     rdi                 ; Restore rdi
    ret                         ; Return back to entry
