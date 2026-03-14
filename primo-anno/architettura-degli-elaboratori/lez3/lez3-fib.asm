.globl _start

.text
# assembly code comes in the '.text' section

_start:
	# N - già caricato su t0
	# int R = 1;
	# int A = 0; int B = 1;
	# while (N > 0) {
	#     R = A + B;
	#     A = B;
	#     B = R;
	#     N = N - 1;
	# }
	# Scrivere programma che implementa questo codice con N in t0. Il risultato finale (R) va lasciato in t1.
	
	li t0, 8		# N
	li t1, 1		# R
	li t2, 0		# A
	li t3, 1		# B
	
for:	
	ble t0, zero, endfor	# Di nuovo condizione invertita per eseguire semrpe il loop altrimenti uscire subito
	
	add  t1, t2, t3
	add  t2, t3, zero
	add  t3, t1, zero
	addi t0, t0, -1
	j for	
endfor:

print:
	mv a0, t1		# Print the result
	li a7, 1
	ecall
		
exit:
	li a7, 10 		# System call for exit: call number 10 = exit
	ecall
