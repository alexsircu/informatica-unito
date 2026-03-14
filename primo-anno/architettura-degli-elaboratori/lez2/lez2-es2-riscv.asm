.globl _start

.text
# assembly code comes in the '.text' section

_start:

	#<assembler code here>\
	# leggo primo numero e lo salvo
	addi x17, x0, 5 # li x17, 5
	ecall
	add x5, x0, x10 # mv x5, x10
	
	# leggo secondo numero e lo salvo
	ecall
	add x6, x0, x10
	
	# faccio la divisione per 2
	add x7, x5, x6
	srai x7, x7, 1
	
	
exit:
	addi x17, x0, 10 # call number 10 = exit
	ecall
