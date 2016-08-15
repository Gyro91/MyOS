[org 0x7c00]
; Tell the assembler where this code will be loaded
    mov bp, 0x9000
    mov sp, bp
    
    mov bx , MSG_REAL_MODE
    call print_string
  
    call switch_to_pm
    
    jmp $
    
    ; Hang
    %include "print_string.asm"
    %include "print_string_pm.asm"
    %include "gdt.asm"
    %include "switch_to_pm.asm"
    
[bits 32]
    ; This is where we arrive after switching
BEGIN_PM:
    mov ebx, MSG_PROT_MODE
    call print_string_pm
        
    jmp $
        
    MSG_REAL_MODE db 'Started in 16-bit real mode', 0
    MSG_PROT_MODE db 'Successfully landed in 32-bit mode', 0
       
    ; Bootsector padding
    times 510-($-$$) db 0

    dw 0xaa55