.globl _start

.text
# assembly code comes in the '.text' section

_start:
	# Tradurre il seguente frammento di codice C in codice assembly RISC-V. Si utilizzi il minor
	# numero possibile di istruzioni. Si supponga che le variabili a, b, c e R siano contenute
	# rispettivamente nei registri t0, t1 e t2.
	# for (i = 0; i < a; i++) {
	#    for (j = 0; j < b; j++) {
	#        R = 2 * R + i + j;
	#    }
	# }
	
	li t0, 10		# a
	li t1, 10		# b
	li t2, 0		# R
	
	li t3, 0		# i
	
fori:
	bge t3, t0, endfori	# i >= a jump
	li t4, 0		# j = 0	

forj:
	bge t4, t1, endforj	# j >= b jump
	
	add t2, t2, t2		# R = 2R
	add t5, t3, t4		# i + j
	add t2, t2, t5		# R + (i + j)
	
	addi t4, t4, 1		# j++
	j   forj
	
endforj:
	addi t3, t3, 1		# i++
	j    forj
	
endfori:
	
exit:
	li a7, 10 		# System call for exit: call number 10 = exit
	ecall
