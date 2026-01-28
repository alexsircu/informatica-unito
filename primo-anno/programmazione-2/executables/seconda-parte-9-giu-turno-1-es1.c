#include <stdio.h>
#include <stdlib.h>

/**
 * Date le dichiarazioni:
*/

typedef struct node IntNode, *IntList;
struct node {
    int data;
    IntList next; 
};

/**
 * e la specifica di funzione:
 * 
 * Modifica *lsPtr togliendo da *lsPtr il suo penultimo nodo, se esiste (ovvero
 * se la lista contiene almeno due elementi),e liberando la memoria da esso occupata.
 * 
 * ESEMPIO: 
 * dato 1 -> 2 -> 3 -> 4 cambia in  1 -> 2 -> 4 e libera la memoria occupata da 3.
 * restituisce :
 * -1 se lstPtr == NULL;
 * 0 se lista vuota o in caso di fallimento
 * 1 in caso di successo
ESEMPI
1. se lsPtr == NULL, dopo l’esecuzione lsPtr == NULL e ritorna -1.
2. se *lsPtr == NULL, dopo l’esecuzione *lsPtr == NULL e ritorna 0.
3. se *lsPtr == [25], dopo l’esecuzione *lsPtr == [25] e ritorna 0.
4. se *lsPtr == [10, 8, 12, 3], dopo l’esecuzione *lsPtr == [10, 8, 3] e restituisce 1.

int eliminaPenultimo(IntList *lsPtr);
realizzarne un'implementazione ITERATIVA.
*/

int eliminaPenultimo(IntList *lsPtr) 
{   
    if (lsPtr == NULL) return -1;
    if (*lsPtr == NULL) return 0;           // lista vuota
    if ((*lsPtr)->next == NULL) return 0;   // un solo elemento

    IntList prevprev = NULL;
    IntList prev = *lsPtr;
    IntList curr = (*lsPtr)->next;

    while (curr->next != NULL)              // finchè curr non è l'ultimo
    {
        prevprev = prev;
        prev = curr;
        curr = curr->next;
    }

    // ora curr = ultimo, prev = penultimo

    if (prevprev == NULL)                   // lista di due elementi: si elimina la testa (penultimo) e resta ultimo
    {
        free(*lsPtr);
        *lsPtr = curr;
    }
    else
    {
        prevprev->next = curr;
        free(prev);
    }

    return 1;
}
