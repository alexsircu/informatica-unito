.globl _start

.data
	var1: .word 0x12345678
	byte1: .byte 0
	byte2: .byte 0
	byte3: .byte 0
	byte4: .byte 0
	
.text
# assembly code comes in the '.text' section

_start:

	#<assembler code here>\
	# load address of var1
	la t0, var1 
	
	# load word value
	lw t1, 0(t0)
	
	# extract byte 1
	andi t2, t1, 0xFF
	
	# extract byte 2
	srli t3, t1, 8
	andi t3, t3, 0xFF
	
	# extract byte 3
	srli t4, t1, 16
	andi t4, t4, 0xFF
	
	# extract byte 4
	srli t5, t1, 24

	# store extracted bytes
	la t0, byte1
	sb t2, 0(t0)
	
	la t0, byte2
	sb t3, 0(t0)
	
	la t0, byte3
	sb t4, 0(t0)
	
	la t0, byte4
	sb t5, 0(t0)
	
exit:
	addi x17, x0, 10 # call number 10 = exit
	ecall
