.globl _start
.data
	array: 		.byte 130, 150, 200	# Array with 3 bytes
	result1: 	.word 0			# result is signed
	result2: 	.word 0			# result is unsigned
.text
# assembly code comes in the '.text' section

_start:
	# Programma che calcoli la somma degli elementi di un array con 3 elementi (byte) in due modi:
	# considerando i valori come numeri con segno (signed byte)
	# considerando i valori come numeri senza segno (unsigned byte)
	# I risultati vanno salvati nelle variabili "result1" e "result2"
	
	# Load address of array
	la t0, array
	
	# Load bytes as signed values
	lb t1, 0(t0)		# First byte as signed
	lb t2, 1(t0)		# Second byte as signed
	lb t3, 2(t0)		# Third byte as signed
	add t4, t1, t2		# t4 = first + second
	add t4, t4, t3		# t4 = (first + second) + third 
	
	# Load bytes as unsigned values
	lbu t1, 0(t0)		# First byte as unsigned
	lbu t2, 1(t0)		# First byte as unsigned
	lbu t3, 2(t0)		# First byte as unsigned
	add t5, t1, t2		# t5 = first + second
	add t5, t5, t3		# t5 = (first + second) + third
	
	# Store results
	la t0, result1
	sw t4, 0(t0)		# Store signed result
	la t0, result2	
	sw t5, 0(t0)		# Store unsigned result
	
exit:
	li a7, 10 		# System call for exit: call number 10 = exit
	ecall
