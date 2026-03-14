#include <stdio.h>

int main(void) {
	int n1, n2;
	
	printf("Inserisci n1: ");
	scanf("%d", &n1);
	printf("Inserisci n2: ");
	scanf("%d", &n2);
	
	printf("La somma n1 + n2 = %d\n", n1 + n2);
	printf("Il prodotto n1 * n2 = %d\n", n1 * n2);
	printf("La divisione n1 / n2 = %d\n", n1 / n2);
	printf("La divisione reale n1 / n2 = %f\n", (float) n1 / n2);
	printf("Il resto della divisione intera n1 / n2 = %d\n", n1 % n2);
}