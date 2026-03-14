.globl _start

.text
# assembly code comes in the '.text' section

_start:

	# Scrivere programma che carichi tre numeri interi su t0, t1 e t2 e inserisca
	# il valore massimo tra i tre nel registro t3. All'inizio t3 vale t0.
	
	li t0, 7
	li t1, 5
	li t2, 9
	mv t3, t0
	
	bge t3, t1, end1	# il ragionamento gira attorno al fatto che in t3 si mette il valore maggiore mano a mano che si va avanti
	mv  t3, t1
end1:	
	bge t3, t2, end2
	mv  t3, t2
end2:
	# t3 ha il maggiore quindi t0 è il maggiore
		
exit:
	li a7, 10 		# System call for exit: call number 10 = exit
	ecall
