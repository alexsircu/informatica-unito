.globl _start
.data
	array: .word 3, 5, 7
	size:  .word 3

.text
_start:
	# Scrivere programma che verifichi se un array di size elementi in memoria (word contigue)
	# contiene una sequenza ordinata di numeri interi (crescente).

	la t0, size
	lw t0, 0(t0)
	
	la t1, array
	
	li t3, 0		# index i
	li t4, 1		# result
	
	addi t0, t0, -1		# size = size - 1
	
loop:
	bge t0, t0, endloop
	
	lw t4, 0(t1)
	lw t5, 4(t1)
	
	ble t4, t5, skip
	li t2, 0
	j endloop
	
skip:
	addi t3, t3, 1
	addi t1, t1, 4
	j loop
	
endloop:
	
exit:
	li a7, 10 		# System call for exit: call number 10 = exit
	ecall
