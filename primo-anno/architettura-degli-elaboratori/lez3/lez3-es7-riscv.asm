.globl _start


.text
# assembly code comes in the '.text' section

_start:
	# Programma che consenta di estrarre i bit da b11 e b16 dal registro x5 e 
	# li sostituisca ai bit da b26 a b31 del registro x6 senza modificare gli altri bit del registro x5 e x6
	
	# Versione a 64 bit (abilitare estensione)
	
	li x5, 0x0000000000000000
	li x6, 0xFFFFFFFFFFFFFFFF
	
	addi x7, x0, 0x3f	# Crea bit mask da 6 bit, tutti i bit a 0 tranne ultimi 6 (meno significativi)
	slli x7, x7, 11		# Shift la mask verso i bit [11-16]
	and  x28, x5, x7		# x28 ha i bit [16-11] uguale a x5 (altri = 0)
	
	slli x7, x7, 15		# Sposta la maschera "sopra" i bit [31-26]
	xori x7, x7, -1		# Invertire i bit (NOT bit a bit) QUESTO PER AZZERARE ZONA DOVE "INCOLLERÒ I BIT NUOVI"
	and  x6, x6, x7		# "Zero out" bit [31-26] di x6
	
	slli x28, x28, 15	# Sposto i bit da x5 salvati in x28
	or   x6, x6, x28	# Carico i bit nelle posizioni [31-26] di x6
	
	
	
exit:
	li a7, 10 		# call number 10 = exit
	ecall
