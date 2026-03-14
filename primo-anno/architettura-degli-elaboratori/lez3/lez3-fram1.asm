.globl _start

.text
# assembly code comes in the '.text' section

_start:
	# x = x - y
	# if (x < 0)
	#     x = 0 
	# y = y - 1
	# Scrivere programma che implementa questo codice con x ed y nei registri t0, t1.
	
	li t0, 7
	li t1, 5
	
	sub t0, t0, t1
	
	bge t0, zero, ENDIF	# in questo modo non si eseguono entrambi casi, sia dentro if che fuori. Si userebbe un jump altrimenti
        li  t0, 0
ENDIF:	
	addi t1, t1, -1
	
exit:
	li a7, 10 		# System call for exit: call number 10 = exit
	ecall
