section .data 
val dq 255.0
section .text
bits 64
default rel
global imgCvtGrayDoubleToInt

imgCvtGrayDoubleToInt:
    ; imgCvtGrayDoubleToInt(a, b, pixels, results)
    ; rcx = a (height)
    ; rdx = b (width)
    ; r8 = pixels
    ; r9 = results
    movsd xmm1, [val]
    xor rbx, rbx             ; Clear rbx (row index)
outer_loop:
    cmp rbx, rcx             ; Compare row index (rbx) with height (rcx)
    jge end_outer_loop       ; Exit if rbx >= height
    
    mov r10, [r8 + rbx * 8]
    mov r11, [r9 + rbx * 8]

    xor r12, r12             ; Clear r12 (column index)
inner_loop:
    cmp r12, rdx             ; Compare column index (r12) with width (rdx)
    jge end_inner_loop       ; Exit if r12 >= width
    
    ; Accessing 2d Array elements
    movsd xmm0, [r10 + r12 * 8]
    VMULSD xmm3, xmm0, xmm1
    CVTSD2SI r14, xmm3
    
    mov [r11 + r12 * 4], r14

    inc r12                  ; Increment column index
    jmp inner_loop           ; Repeat inner loop
end_inner_loop:
    inc rbx                  ; Increment row index
    jmp outer_loop           ; Repeat outer loop
end_outer_loop:
    ret
