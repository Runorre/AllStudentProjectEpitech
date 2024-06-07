BITS 64

section .text

global strstr

strstr:
    xor rbx, rbx
    xor r8, r8
    xor r9, r9

    loop_str:
        movzx rcx, BYTE [rdi + r8]
        movzx rdx, BYTE [rsi]
        cmp rdx, 0
        je return_correct
        cmp rcx, 0
        je return_null
        cmp rcx, rdx
        je pre_check_neelde
        inc r8
        jmp loop_str
    
    pre_check_neelde:
        mov r9, r8
        xor rbx, rbx
        jmp check_needle

    reset_loop:
        inc r8
        xor r9, r9
        jmp loop_str

    check_needle:
        inc rbx
        inc r9
        movzx rcx, BYTE [rdi + r9]
        movzx rdx, BYTE [rsi + rbx]
        cmp rcx, 0
        je check_correct_rdx
        cmp rdx, 0
        je return_correct
        cmp rcx, rdx
        je check_needle
        jne reset_loop

    check_correct_rdx:
        cmp rdx, 0
        je return_correct
        jne return_null

    return_correct:
        lea rax, [rdi]
        add rax, r8
        ret
    
    return_null:
        xor rax, rax
        ret

