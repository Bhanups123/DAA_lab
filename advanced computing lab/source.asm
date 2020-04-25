section .data

section .text
	global stats
	stats:
        	push r12
		mov r12d,0
		mov eax, dword[rdi]
        	add r12d,eax
		mov eax, dword[rdi+4]
		add r12d, eax
		mov eax, dword[rdi+8]
		add r12d, eax
		mov eax, dword[rdi+12]
		sub r12d, eax
		mov dword[rdx],r12d
		pop r12
		syscall
		ret
	last:
		mov rax,60
		mov rdi,0
		syscall
