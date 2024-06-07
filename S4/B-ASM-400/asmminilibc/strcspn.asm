BITS 64

section .text

global strcspn

strcspn:
    xor r8, r8
    xor r9, r9

    checkaction:
        movzx rcx, BYTE [rdi + r8]
        movzx rdx, BYTE [rsi + r9]
        cmp rcx, 0
        je return_correct
        cmp rdx, 0
        je reset_loop
        cmp rcx, rdx
        je return_correct
        jmp pre_check_loop

    pre_check_loop:
        inc r9
        jmp checkaction

    reset_loop:
        xor r9, r9
        inc r8
        jmp checkaction

    return_correct:
        mov rax, r8
        ret

