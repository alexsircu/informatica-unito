.globl _start

.text
# assembly code comes in the '.text' section

_start:
	# Scrivere programma che restituisce sul registro t2 il numero di bit uguali a 1 contenuti
	# nel valore binario presente nel registro t0. Per esempio, se t0 ha il valore binario equivalente
	# al numero intero 37, il risultato atteso è 3.
	
	li t0, 37		# Integer number
	li t1, 1		# Equals to 0x00000001 and equals to 00000000 00000000 00000000 00000001
	li t2, 0		# Result
	
	li t4, 32		# The max number of iterations
	li t5, 1		# Counter
	
for:
	bgt t5, t4, endfor
	
	AND  t3, t0, t1		# And between the number and the mask
	add  t2, t2, t3		# Increment the result by 1 (if LSB is 1) or 0 (if LSB is 0)
	srli t0, t0, 1 		# Shift right logic by 1 to update the LSB and check the next bit
	
	addi t5, t5, 1		# Increment counter by 1
	j    for
endfor:

print:
	mv a0, t2		# Print the result
	li a7, 1
	ecall
		
exit:
	li a7, 10 		# System call for exit: call number 10 = exit
	ecall
