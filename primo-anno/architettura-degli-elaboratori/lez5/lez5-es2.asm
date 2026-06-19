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
	
	la  t4, v1		# get the v1 address
	lw  t0, 0(t4)		# copy the first word into t0
	lw  t1, 4(t4)		# copy the second word into t1
	lw  t2, 8(t4)		# copy the third word into t2
	
	mv  t3, t0		# t3 will hold the max among the three
	
	bge t3, t1, skip1	# check whether t1 < t0
	add t3, t1, zero	# if t1 > t0, hold it
skip1:	
	bge t3, t2, skip2	# check whether t2 < max(t1, t0)
	add t3, t2, zero	# if t2 > max(t1, t0), hold it
skip2:
	sw  t3, 12(t4)		# store t3 into memory
	
exit:
	addi a0, t3, 0
	li   a7, 10 		# System call for exit: call number 10 = exit
	ecall
