.globl _start
.data
	array:  .word 4, 5, 7, 8, 9, 2	# 6 elements array
	size:   .word 6				# could be .half too, if it is enough to store the size
	result: .word 0 
.text
_start:
	# Scrivere programma che salva la somma degli elementi dell'array in una variabile identificata
	# con l'etichetta result.
	
	la   t0, array
	
	la   t1, size
	lw   t1, 0(t1)

	li   t2, 0 				# Sum
	
for:
	blez t1, endfor
	
	lw  t4, 0(t0)				# To load the next array element t0 should be modified
	add t2, t2, t4				# Sum = sum + element value
	
	addi t0, t0, 4				# Add 4 to t0 to get the next array element
	addi t1, t1, -1				# Size--
	j for

endfor:

	la t5, result
	sw t2, 0(t5)

exit:
	li   a7, 10 				# System call for exit: call number 10 = exit
	ecall