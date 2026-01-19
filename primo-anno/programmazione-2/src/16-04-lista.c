#include "16-04-lista.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// typedef struct s1 elem,*elemptr;
/*struct s1 {int content; elemptr next;};  // lista interi

typedef struct s2  lista,*listaptr;
struct s2 {elemptr first;};
*/

char buf[1024]; // sigsegv per liste grandi
int pos = 0;

char* stampaListaRic(listaptr L) 
{
  // versione abbreviata: sprintf() restituisce quanti char ha stampato
  // se la stringa che concateno va fuori fai realloc(), stringa dinamica*

  pos += sprintf(buf + pos, "[ ");
  for (elemptr pt = L->first; pt != NULL; pt = pt->next) {
    if (pt->tag == NORMALE) 
      pos += sprintf(buf + pos, "%ld ", (long)pt->content);
    else 
      stampaListaRic(pt->content);
  }
  pos += sprintf(buf + pos, "] ");
  return buf;
}

char* stampaLista(listaptr L)
{
  // fatta questa funzione perchè in questo modo pos non viene aggiornata
  // nella soluzione prcedente senza stampaListaRic, c'era una sola funzione
  // che ogni volta che veniva richiamata azzerava pos

  // per migliorare questa funzione e per non avere un buf globale che rimane
  // sempre allocato, lo si potrebbe allocare qua dentro e lo si potrebbe passare
  // alla funzione stampaListaRic come parametro e alla fine lo si potrebbe 
  // deallocare con la free

  // altro problema con stringa fissa, capacità massima. Si può usare qualcosa
  // con una stringa dinamica (per esempio codice dell'esercizio fatto nelle lezioni
  // precedenti)

  pos = 0;
  stampaListaRic(L);
  buf[pos] = '\0';
  return buf;
}

char buf11[64];
char* toStr(elemptr el)
{
  if (el == NULL)
    return "NULL";

  int val = sprintf(buf11,
    "TAG = %s, content = %ld, next = %p", el->tag == NORMALE ? "NORMALE":"LISTA",
    (long)(el->content), el->next);

  buf11[val] = '\0';
  return buf11;
}

listaptr crealista(void) 
{
  listaptr ret = malloc(sizeof(lista));
  if (ret != NULL) {
    ret->first = NULL;
  }
  return ret;
}

int test_crealista(void) 
{
  listaptr val = crealista();
  if (val != NULL && val->first != NULL) {
    return 1;
  }
  return 0;
}

elemptr creaelem(/*int*/ void *valore, enum TAG tag) 
{
  elemptr ret = malloc(sizeof(elem));
  if (ret != NULL) {
    ret->tag = tag;
    ret->next = NULL;
    ret->content = valore;
  }
  return ret;
}

elemptr elementAt(listaptr l, int *indexes)
{
  if (*indexes < 0) // indice non trovato
    return NULL;

  if (l == NULL)
    return NULL;

  int cursor = 0;
  elemptr *el = &l->first;
  while (*el != NULL && cursor < *indexes) 
  {
    el = &(*el)->next;
    cursor++;
  }

  if (cursor < *indexes) // ultimo indice
    return NULL;

  if (*(indexes + 1) < 0)
    return *el;

  if ((*el)->tag == NORMALE)
    return NULL;

  return elementAt((*el)->content, indexes + 1); // elemento è una lista
}

int insert(enum TAG tag, /*int*/ void *val, listaptr l, int index) // inserisce a posizione index
{
  if (l == NULL || index < 0) return 1;

  int cursor = 0;
  elemptr *el = &l->first;
  while (cursor < index && *el != NULL)
  {
    el = &(*el)->next;
    cursor++;
  }

  if (cursor < index) { // non ci sono abbastanza elementi dentro la lista
    return 1; 
  }

  elemptr new = creaelem(val, tag);
  if (new != NULL) {
    new->next = *el;
    *el = new;
    return 0;
  }

  return 1;
}

int test_insert_remove(void) 
{
  int failures = 0;
  int retval = 0;
  char* result = NULL;
  
  listaptr lp = crealista();
  insert(NORMALE, (void*)1, lp, 0);

  listaptr lp1 = crealista();
  insert(LISTA, (void*)lp1, lp, 0); // inserisco lp1 dentro lp

  insert(NORMALE, 0, lp1, 0); // inserisco 0, nella posizione 0 della lista lp1

  result = stampaLista(lp);
  if (strcmp(result, "1 ") != 0) {
    failures += 1;
    fprintf(stderr, "expected: '%s' found: '%s'\n", "1 ", result);
  }

  return failures;
}

int removeel(listaptr l, int index)
{
  if (l == NULL || index < 0) return 1;

  int cursor = 0;
  elemptr *el = &l->first;
  while (cursor < index && *el != NULL)
  {
    el = &(*el)->next;
    cursor++;
  }

  if (cursor < index) return 1; // non ci sono abbastanza elementi dentro la lista 

  elemptr current = *el;
  *el = (*el)->next;
  free(current);
  return 0;
}

int indexof(/*int*/ void *val, listaptr l) // restituisce posizione oppure -1 se manca
{
  if (l == NULL || l->first == NULL) return -1;

  int cursor = 0;
  elemptr el = l->first;
  while (el != NULL)
  {
    if (el->content == val)
    {
      return cursor;
    }
    el = el->next;
    cursor++;
  }

  return -1;
}

int test_indexof(void)
{
  int failures = 0;
  int retval = 0;
  char *result = NULL;
  listaptr lp = crealista();

  // posizione del valore 0
  insert(NORMALE, (void*)0, lp, 0);
  //retval = indexesof(0, lp);
  result = stampaLista(lp);

  if (retval != 0) 
  {
    failures += 1;
    fprintf(stderr, "expected: 0 found: %d  ;list = %s\n", retval, result) ;
  }

  return failures;
}

listaptr indexesof(/*int*/ void *val, listaptr l) // crea lista di indici di val
{
  val = NULL;
  l = NULL;
  return NULL;
}

int test_list(void)
{
  int failures = 0;
  failures += test_crealista();
  failures += test_insert_remove();
  failures =+ test_indexof();
  return failures;
}
