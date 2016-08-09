; This function prints on the screen the value of dx in hex
[org 0x7c00]
	
print_hex:
	pusha
	mov al, 48 ; value of the char zero
	mov ah, 1  ; weight of the bit 
	mov cl, 0
	mov ch, 3

lp1:    ; A cycle of 4 iterations for each characters	
	cmp ch, 0
	jl pr_scr
	mov cl, 0
	mov bx, 0x0001

lp2:	; A cycle for evaluating the 4-bits associated 
	; to one char
	cmp cl, 4
	je next_i1
	and bx, dx
	cmp bx, 0
	je next_i2
	add al, ah
	
next_i2:
	add ah, ah ; Increasing the weight 
	add cl, 1
	shr dx, 1
	mov bx, 0x0001
	jmp lp2	
	
next_i1:
	mov bx, HEX_OUT
	add bl, 2
	add bl, ch
	cmp al, 57 	; If the val is greater than		   	
	jle not_inc 	; the val associated to 9, then    	
	add al, 7	; we must add an offset
not_inc:
	mov [bx], al
	mov al, 48
	mov ah, 1
	sub ch, 1
	jmp lp1
	
pr_scr:	
	mov bx, HEX_OUT	
	call print_string

	popa
	ret

HEX_OUT: db '0x0000',0		

%include "print_string.asm"
