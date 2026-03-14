#include <stdio.h>

int main(void) {
	const float prezzo_orecchiette = 1.5;
	const float prezzo_kg_pomodori = 2.5;
	int num_pacchi;
	float num_kg;
	
	printf("Quanti pacchi di orecchiette vuoi comprare?\n");
	scanf("%d", &num_pacchi);
	printf("Quanti kg di pomodori vuoi comprare?\n");
	scanf("%f", &num_kg);
	
	float tre_pacchi_orecchiette = prezzo_orecchiette * num_pacchi;
	float pomodori_1_kg_mezzo = prezzo_kg_pomodori * num_kg;
	float totale = tre_pacchi_orecchiette + pomodori_1_kg_mezzo;
	
	printf("Prezzo orecchiette: %f\n", tre_pacchi_orecchiette);
	printf("Prezzo pomodori: %f\n", pomodori_1_kg_mezzo);
	printf("Il totale speso è: %f", totale);
}