BITS 64

section .text

global strcmp

strcmp:
    xor rax, rax
    xor rbx, rbx
    xor rcx, rcx

    main_process:
        cmp BYTE [rdi + rax], 0
        jz check_end_rdi
        cmp BYTE [rsi + rax], 0
        jz check_end_rsi
        movzx rcx, BYTE [rdi + rax]
        movzx rdx, BYTE [rsi + rax] 
        cmp rcx, rdx
        je incremation
        ja return_pos
        jb return_neg
    
    incremation:
        inc rax
        jmp main_process

    check_end_rdi:
        cmp BYTE [rsi + rax], 0
        je return_zero
        jne return_neg
    check_end_rsi:
        cmp BYTE [rdi + rax], 0
        je return_zero
        jne return_pos

    return_zero:
        xor rax, rax
        ret
    return_neg:
        mov rax, -1
        ret
    return_pos:
        mov rax, 1
        ret