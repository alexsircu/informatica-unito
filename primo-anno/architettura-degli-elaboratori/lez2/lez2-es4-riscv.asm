.globl _start
.data
	num1:		.word 5		# First number
	num:		.word 7		# Second number
	result:		.word 0		# Location for result

.text
# assembly code comes in the '.text' section

_start:
	# Programma che prende in input da memoria due numeri interi
	# e calcoli la somma dei quadrati di entrambi i numeri.
	# Il risultato deve essere salvato in un'ulteriore posizione di memoria contigua
	
	# Load address of data
	la t0, num1
	
	# Load the two numbers
	lw t1, 0(t0)		# t1 = first number
	lw t2, 4(t0)		# t2 = second number
	
	# Calculate squares
	mul t3, t1, t1		# t3 = t1 * t1
	mul t4, t2, t2		# t4 = t2 * t2
	
	# Sum the squares
	add t5, t3, t4		# t5 = t3 + t4
	
	# Store the result
	sw t5, 8(t0)		# Store at result location
	
exit:
	li a7, 10 # call number 10 = exit
	ecall
