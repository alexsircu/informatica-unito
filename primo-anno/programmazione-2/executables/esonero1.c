#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define N 12

/* INSERIRE QUI EVENTUALI FUNZIONI AUSILIARIE (CON COMMENTO SIGNIFICATIVO IN TESTA) */

/**
 * @brief Dato un array di caratteri ac, con n elementi, restituisce un nuovo 
 * array (di lunghezza n) ottenuto da ac eliminando tutte le occorrenze delle
 * cifre ('0'...'9'), trasformando tutte le occorrenze delle lettere minuscole
 * 'k' e 'h' nelle corrispondenti lettere maiuscole, e riempiendo le eventuali
 * posizioni rimaeste libere alla fine del nuovo array con delle occorrenze del
 * carattere '#'
 * 
 * ESEMPIO: dato ac = '56akhra45', diventa 'aKHra####'
 */

char* change(char* ac, int n)
{
    char* new_array = (char*)malloc(sizeof(char) * n);
    int pos = 0;

    for (int i = 0; i < n; i++)
    {
        if (isdigit((unsigned char)ac[i]))
            continue;

        if (ac[i] == 'h')
            new_array[pos] = 'H';
        else if (ac[i] == 'k')
            new_array[pos] = 'K';
        else
            new_array[pos] = ac[i];
        
        pos++;
    }

    if (pos < N - 1)
    {
        for (; pos < N; pos++)
        {
            new_array[pos] = '#';
        }
    }

    return new_array;
}

int main(void)
{
    char ac[N] = {'a','1','b','2','c','3','d','4','k','5','h','g'};
    char* new_ac = change(ac, N);
    for (int i = 0; i < N; i++)
    {
        printf("%c ", new_ac[i]);
    }
    free(new_ac);
}
