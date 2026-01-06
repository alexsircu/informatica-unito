#ifndef LISTA_H
#define LISTA_H

/*
 * FARE ATTENZIONE:
 * La struct `lista` NON rappresenta un nodo della lista,
 * ma un contenitore che mantiene il puntatore al primo nodo (`first`).
 * In questo modo la testa della lista può essere modificata
 * dalle funzioni senza usare puntatori a puntatori.
 */

typedef struct s1 elem, *elemptr;

struct s1 {
  void *content; //int content;
  elemptr next;
}; // lista interi

typedef struct s2 lista, *listaptr;
struct s2 {
  elemptr first;
};

// implementate le funzioni:
listaptr crealista(void);
int insert(/*int*/ void *val, listaptr l, int index); // inserisce a posizione index
int indexof(/*int*/ void *val, listaptr l); // restituisce posizione oppure -1 se manca
listaptr indexesof(/*int*/ void *val, listaptr l); // crea lista di indici di val
int test_list(void);
#endif
