BITS 64

section .text

global memset

memset:
    xor rax, rdi
    xor rcx, rcx
    loop:
        cmp rcx, rdx
        je return_pointer
        mov BYTE [rax + rcx], sil
        inc rcx
        jmp loop
    
    return_pointer:
        ret