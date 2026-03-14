.globl _start

.text
# assembly code comes in the '.text' section

_start:
	#<assembler code here>
	li x5, 0xAAAAAAAA
	li x6, 0x12345678
	
	slli x7, x5, 4
	or x7, x7, x6
	
	slli x7, x6, 4
	srli x7, x5, 3
	
	andi x7, x7, 0xFF
	
exit:
	addi x17, x0, 10 # call number 10 = exit
	ecall