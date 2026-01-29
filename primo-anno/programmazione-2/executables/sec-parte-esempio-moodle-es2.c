#include <stdio.h>
#include <stdlib.h>

typedef struct intNode IntNode, *IntList;
struct intNode {
    int data;
    IntList next;
};

/* =================== */
/* Funzioni ausiliarie */
/* =================== */

/* Crea una lista a partire da un array di interi */
IntList create_list_from_array(int arr[], int n)
{
    IntList head = NULL;
    IntList tail = NULL;

    for (int i = 0; i < n; i++) {
        IntList new_node = malloc(sizeof(IntNode));
        if (!new_node) return head; // per test va bene così

        new_node->data = arr[i];
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    return head;
}

/* Stampa la lista (utile per debug visivo) */
void print_list(IntList l)
{
    printf("[");
    while (l != NULL) {
        printf("%d", l->data);
        if (l->next != NULL) printf(", ");
        l = l->next;
    }
    printf("]\n");
}

/* Libera tutta la lista */
void free_list(IntList l)
{
    while (l != NULL) {
        IntList tmp = l;
        l = l->next;
        free(tmp);
    }
}

/**
 * Implementare una funzione che calcola il numero di foglie presenti nell'albero:
 * 
 * @brief Riorganizza i nodi di *lsPtr invertendone l’ordine. 
 * Ad ad esempio, data [1, 2,3] la trasforma in [3, 2,1]. Non alloca nuova memoria sullo heap. 
 * void reverse(IntList* lsPtr);
 * 
 * realizzarne un'implementazione basata sull'iterazione.
 * 
 */
void reverse(IntList* lsPtr)
{
    if (lsPtr == NULL || *lsPtr == NULL) return;

    IntList prev = NULL;
    IntList curr = *lsPtr;
    IntList next = NULL;

    while (curr != NULL)
    {
        next = curr->next;              // salvo il prossimo
        curr->next = prev;              // inverto il link
        prev = curr;                    // avanzo prev
        curr = next;                    // avanzo curr
    }
    
    *lsPtr = prev;                      // nuova testa
}

int main(void)
{
    int data[] = {1, 2, 3, 4};
    IntList l = create_list_from_array(data, 4);

    printf("Prima: ");
    print_list(l);

    reverse(&l);

    printf("Dopo:  ");
    print_list(l);

    free_list(l);
    return 0;
}