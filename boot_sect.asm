[org 0x7c00]
; Tell the assembler where this code will be loaded
KERNEL_OFFSET equ 0x1000
    
    mov [BOOT_DRIVE], dl
    
    mov bp, 0x9000
    mov sp, bp
    
    mov bx, MSG_REAL_MODE
    call print_string
  
    call load_kernel

    call switch_to_pm
    
    jmp $
    
    ; Hang
    %include "32bit-print.asm"
    %include "print_hex.asm"
    %include "boot_sect_disk.asm"
    %include "32bit-gdt.asm"
    %include "32bit-switch.asm"
[bits 16]

load_kernel:
    mov bx, MSG_LOAD_KERNEL
    call print_string

    mov bx, KERNEL_OFFSET
    mov dh, 15
    mov dl, [BOOT_DRIVE]
    call disk_load

    ret
    
[bits 32]
    ; This is where we arrive after switching
BEGIN_PM:
    mov ebx, MSG_PROT_MODE
    call print_string_pm
    call KERNEL_OFFSET
        
    jmp $
    
    ; Global variables
    BOOT_DRIVE db 0    
    MSG_REAL_MODE db 'Started in 16-bit real mode', 0
    MSG_PROT_MODE db 'Successfully landed in 32-bit mode', 0
    MSG_LOAD_KERNEL db "Loading kernel into memory", 0   
    ; Bootsector padding
    times 510-($-$$) db 0

    dw 0xaa55
