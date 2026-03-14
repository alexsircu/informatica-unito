.globl _start

.text
# assembly code comes in the '.text' section

_start:
	# x = (x - 2) + y
	# if (x < y)
	#     x = x + 1
	# else 
	#     y = y + 1
	# Scrivere programma che implementa questo codice con x ed y nei registri t0, t1.
	
	li t0, 7		# x
	li t1, 5		# y
	
	addi t0, t0, -2
	add  t0, t0, t1
	
	bge  t0, t1, ELSE	# con condizione inversa si replica correttamente il flusso dell'if (come già conosciuto)
        addi t0, t0, 1
        j ENDIF
ELSE:	
	addi t1, t1, 1
ENDIF:
		
exit:
	li a7, 10 		# System call for exit: call number 10 = exit
	ecall
