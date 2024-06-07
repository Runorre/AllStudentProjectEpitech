BITS 64

section .text

global strrchr

strrchr:
    xor rbx, rbx
    cmp sil, 0
    je return_empty
    cmp BYTE [rdi], 0
    je return_null

    loop_to_end:
        cmp BYTE [rdi + rbx], 0
        je finding
        inc rbx
        jmp loop_to_end
    
    finding:
        dec rbx
        cmp BYTE [rdi + rbx], sil
        je return_string
        cmp rbx, 0
        je return_null
        jmp finding
    
    return_string:
        lea rax, [rdi]
        add rax, rbx
        ret

    return_empty:
        cmp BYTE [rdi + rbx], 0
        je return_string
        inc rbx
        jmp return_empty
    
    return_null:
        xor rax, rax
        ret