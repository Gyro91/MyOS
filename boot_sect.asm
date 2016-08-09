	
[org 0x7c00]
	mov ah, 0x0e


	mov bp, 0x8000
	mov sp, bp
	
	mov dx, 0xFE79
	call print_hex
		
	jmp $
	%include "print_hex.asm"
	
	times 510-($-$$) db 0
	
	dw 0xaa55
