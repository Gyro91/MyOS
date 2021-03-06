[org 0x7c00]
; Tell the assembler where this code will be loaded
KERNEL_OFFSET equ 0x1000
    
    mov [BOOT_DRIVE], dl
    
    mov bp, 0x9000
    mov sp, bp
  
    call load_kernel

    call switch_to_pm
    
    jmp $
    
    ; Hang
    %include "boot/32bit-print.asm"
    %include "boot/print_string.asm"
    %include "boot/print_hex.asm"
    %include "boot/boot_sect_disk.asm"
    %include "boot/32bit-gdt.asm"
    %include "boot/32bit-switch.asm"
[bits 16]

load_kernel:
    mov bx, MSG_LOAD_KERNEL
   ; call print_string

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
    MSG_PROT_MODE db 'Successfully landed in 32-bit mode', 0
    MSG_LOAD_KERNEL db "Loading kernel into memory", 0   
    ; Bootsector padding
    times 510-($-$$) db 0

    dw 0xaa55
