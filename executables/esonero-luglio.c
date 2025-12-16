#include <stdio.h>
#include <stdlib.h>


/* INSERIRE QUI EVENTUALI FUNZIONI AUSILIARIE (CON UN COMMENTO SIGNIFICATIVO IN TESTA) */

typedef struct node CharNode, *CharList;
struct node {
    char data;
    CharList next;
};

void add_node(char const* s, CharList *curr)
{
    while (*s != '\0')
    {
        // crea nodo
        CharNode *node = (CharNode*)malloc(sizeof(CharNode));

        // aggiorno i dati del nodo
        node->data = *s;
        node->next = NULL;

        // aggiungo il nodo alla lista
        (*curr)->next = node;

        // andare avanti con la lista
        *curr = node;

        // andare avanti con la stringa
        s++;
    }
}

/**
* Data una lista di caratteri *ptr e una stringa str, modifica *ptr inserendo
* un nodo nuovo per ciascun carattere di str. I nodi nuovi vanno inseriti dopo
* la prima occorrenza del carattere 'Z' nella lista. Se 'Z' non occorre vanno
* inseriti in coda alla lista. I nuovi nodi vanno inseriti nello stesso ordine
* con cui si susseguono nella stringa.
*
* Non considera l'eventualità che la malloc fallisca.
* Se ptr == NULL restituisce 0, altrimenti restituisce 1.
* Se s == NULL o ptr == NULL, non modifica ptr.
*
* ESEMPI:
* (1) data *ptr == [A,x,8] ed s == "k$2e" restituisce 1 e causa *ptr == [A,x,8,k,$,2,e]
* (2) data ptr == NULL ed s == "Pluto" restituisce 0 e non modifica ptr
* (3) data *ptr == [] ed s == "Pluto" restituisce 1 e causa *ptr == [P,l,u,t,o]
* (4) data *ptr == [P,A,Z,Z,O] ed s == "Pluto" restituisce 1 e causa *ptr == [P,A,Z,P,l,u,t,o,Z,O]
* (5) data *ptr == [p,a,z,z,o] ed s == "Pluto" restituisce 1 e causa *ptr == [p,a,z,z,o,P,l,u,t,o]
* (6) data *ptr == [p,a,z,z,o] ed s == NULL restituisce 1 e non modifica ptr
*/

int insert(CharList *ptr, char const* s)
{
    // CharList è un puntatore ad un puntatore

    if (ptr == NULL) return 0;
    if (s == NULL) return 1;

    // lista vuota
    if (*ptr == NULL)
    {
        // il primo nodo lo creo e poi uso la funzione per aggiungere gli altri nodi
        CharList head_node = (CharList)malloc(sizeof(CharNode));
        head_node->data = *s;
        head_node->next = NULL;

        // aggiorno la lista con la nuova testa
        *ptr = head_node;

        // vado avanti con la stringa perchè il primo carattere l'ho già valutato
        s++;

        // gli passo il nodo in testa e non la lista
        add_node(s, &head_node);
    }
    else
    {
        // uso current per non perdere la testa della lista (dato che sto direttamente lavorando
        // su di essa)
        CharList current = *ptr;

        // itero sulla lista fino a quando non trovo il nodo corretto
        // il while si blocca quando incontra 'Z' oppure quando il next è NULL
        // una volta arrivato al nodo corretto posso creare i nuovi nodi per ogni carattere
        // e aggiungerli alla lista partendo dal punto corretto
        while (current->next != NULL && current->data != 'Z')
        {
            current = current->next;
        }

        // salvato il nodo successivo, sia che sia un indirizzo, sia che sia NULL
        // così dopo che ho creato tutti i nodi e li ho aggiunti alla lista
        // posso collegare il pezzo restante di lista
        CharList tmp_next = current->next;

        // aggiungo nodi
        add_node(s, &current);

        // aggiungo lista restante
        current->next = tmp_next;
    }

    return 1;
}
