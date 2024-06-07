BITS 64

section .text

global strchr

strchr:
    loop:
        cmp BYTE [rdi], sil
        je returnchar
        cmp BYTE [rdi], 0
        je returnnothing
        inc rdi
        jmp loop

    returnchar:
        lea rax, [rdi]
        ret

    returnnothing:
        xor rax, rax
        ret