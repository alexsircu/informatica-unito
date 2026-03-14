.globl _start

.data
	numbers: .word 12, 16, 20, 24
	result: .word 0

.text
# assembly code comes in the '.text' section

_start:

	#<assembler code here>\
	# load address of first number
	la t0, numbers 
	
	# load the four values
	lw t1, 0(t0)
	lw t2, 4(t0)
	lw t3, 8(t0)
	lw t4, 12(t0)
	
	# calculate sum
	add t5, t1, t2
	add t5, t5, t3
	add t5, t5, t4
	
	# divide by 4
	srai t5, t5, 2
	
	# store result in memory
	la t0, result
	sw t5, 0(t0)
	
exit:
	addi x17, x0, 10 # call number 10 = exit
	ecall
