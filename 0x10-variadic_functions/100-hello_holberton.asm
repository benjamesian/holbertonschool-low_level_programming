	global	main

	section .text
main:	mov	rax, 1		; start call to write
	mov	rdi, 1		; write to stdout
	mov	rsi, msg	; address of message to write
	mov	rdx, 17		; length of string to write
	syscall			; execute write
	mov	rax, 60		; start call to exit
	xor	rdi, rdi	; exit with code 0
	syscall			; execute exit

	section .data
msg:	db	"Hello, Holberton", 10 ; message to print (with newline)
