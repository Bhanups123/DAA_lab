; .text section is for the instructions
section .text
    global addDiff
    addDiff:
        
        ; Saved prior r10 value
        push r10
        
        ; Initializing register r10d (32-bit) to 0. Result is to be stored in r10d
        mov r10d,0
        
        ; Moved first number a to register ebx 'dword takes 32 bit from rdi'
        mov ebx, dword[rdi]

        ; Added the ebx value to r10d i.e. r10d = r10d + ebx 
        add r10d,ebx

        ; Moved second number b to register ebx 'dword takes 32 bit from rdi+4'
        mov ebx, dword[rdi+4]

        ; Added the ebx value to r10d i.e. r10d = r10d + ebx 
        add r10d, ebx

        ; Moved third number c to register ebx 'dword takes 32 bit from rdi+8'
        mov ebx, dword[rdi+8]

        ; Added the ebx value to r10d i.e. r10d = r10d + ebx 
        add r10d, ebx

        ; Moved fourth number d to register ebx 'dword takes 32 bit from rdi+8'
        mov ebx, dword[rdi+12]

        ; Subtracted the ebx value to r10d i.e. r10d = r10d - ebx 
        sub r10d, ebx

        ; Moved the result from r10d to destination index (32 bit).
        mov dword[rdx],r10d

        ; Minimal clean-up 
        pop r10
        syscall
        ret
        
    last:
        mov rax,60
        mov rdi,0
syscall
