#include <stdio.h>

int main() {
	// primo es
	printf("Prima riga\n");
	printf("Seconda riga\n");

	// secondo es	
	printf("Prova prima riga di nuovo\nProva seconda riga\n");
	
	// terzo es
	int num_1, num_2;
	printf("Inserisci il primo numero: ");
	scanf("%d", &num_1);
	printf("Inserisci il secondo numero: ");
	scanf("%d", &num_2);
	printf("Il primo numero inserito è: %d\n", num_1);
	printf("Il secondo numero inserito è: %d\n", num_2);
	
	// quarto es
	int a = 23;
	int b = 89;
	int somma = a + b;
	
	printf("Il valore di a è: %d\n", a);
	printf("Il valore di b è: %d\n", b);
	printf("La somma di a e b è: %d\n", somma);
	
	// quinto es
	int x = 5;
	int y = 8;
	int z = 11;
	int prodotto = x * y * z;
	
	printf("Il valore di x è: %d\n", x);
	printf("Il valore di y è: %d\n", y);
	printf("Il valore di z è: %d\n", z);
	printf("Il prodotto di x, y e z è: %d\n", prodotto);
	
	return 0;
}

