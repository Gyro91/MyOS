
[org 0x7c00]
	
print_string:
	pusha
	mov ah, 0x0e
loop_ps1:
	cmp byte [bx], 0
	je end_ps1
 	mov al, [bx]
	int 0x10
	add bx, 1
	jmp loop_ps1	
end_ps1:	
	popa
	ret		
