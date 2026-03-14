#include <stdio.h>

int main(void) {
    int v1, v2, v3, v4;
	
	printf("Inserisci 4 numeri interi:\n");
	scanf("%d %d %d %d", &v1, &v2, &v3, &v4);
    printf("v1: %d, v2: %d, v3: %d, v4: %d\n", v1, v2, v3, v4);

    // v1 prende il valore di v2
	// v2 prende il valore di v3
 	// v3 prende il valore di v4
	// v4 prende il valroe di v1
    int temp = v1;
    v1 = v2;
	v2 = v3;
	v3 = v4;
    v4 = temp;

    printf("v1: %d, v2: %d, v3: %d, v4: %d\n", v1, v2, v3, v4);
}