.globl _start

.text
# assembly code comes in the '.text' section

_start:
	# Scrivere programma che calcoli la somma dei primi N quadrati perfetti.
	# Il programma deve assumere che N sia nel registro t0 e lasciare il risultato sul registro t1.
	
	li   t0, 10		# N
	li   t1, 0 		# S
	li   t2, 1		# Iterator

for:	
	bgt  t2, t0, endfor	# if (i > N) jump
	
	mul  t3, t2, t2		# t3 = i*i 	   
	add  t1, t1, t3		# S = S + t3
	
	addi t2, t2, 1		# i++
	j    for		# jump for     

endfor:	
	
exit:
	li a7, 10 		# System call for exit: call number 10 = exit
	ecall
