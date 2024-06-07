BITS 64

section .text

global strcasecmp

strcasecmp:
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
        jmp check_majima_step1_rcx
    
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

    check_majima_step1_rcx:
        cmp rcx, 65
        jae check_majima_step2_rcx
        jmp check_majima_step1_rdx
    check_majima_step2_rcx:
        cmp rcx, 90
        jbe convert_majima_rcx
        jmp check_majima_step1_rdx
    convert_majima_rcx:
        add rcx, 32
        jmp check_majima_step1_rdx

    check_majima_step1_rdx:
        cmp rdx, 65
        jae check_majima_step2_rdx
        jmp comparaison
    check_majima_step2_rdx:
        cmp rdx, 90
        jbe convert_majima_rdx
        jmp comparaison
    convert_majima_rdx:
        add rdx, 32
        jmp comparaison

    comparaison:
        cmp rcx, rdx
        je incremation
        ja return_pos
        jb return_neg

    return_zero:
        xor rax, rax
        ret
    return_neg:
        mov rax, -1
        ret
    return_pos:
        mov rax, 1
        ret