.globl _start
.data
	v1:     .word 1
	v2:     .word 2
	v3:     .word 3
	result: .word 0
.text
_start:
	# Scrivere programma che calcoli il massimo tra tre numeri interi presenti nella memoria
	# in word contigue (variabili x, y e z). Il valore massimo va salvato nella variabile result.
	
	
exit:
	addi a0, t3, 0
	li   a7, 10 		# System call for exit: call number 10 = exit
	ecall
