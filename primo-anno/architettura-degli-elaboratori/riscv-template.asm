.globl _start

.text
# assembly code comes in the '.text' section

_start:

	#<assembler code here>
	
exit:
	li a7, 10 		# System call for exit: call number 10 = exit
	ecall
