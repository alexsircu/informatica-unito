#include "09-04-lista.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// typedef struct s1 elem,*elemptr;
/*struct s1 {int content; elemptr next;};  // lista interi

typedef struct s2  lista,*listaptr;
struct s2 {elemptr first;};
*/

char buf[1024]; // sigsegv per liste grandi
char *stampaLista(listaptr L) 
{
  // versione abbreviata: sprintf() restituisce quanti char ha stampato
  int pos = 0;
  for (elemptr pt = L->first; pt != NULL; pt = pt->next) {
    //pos += sprintf(buf + pos, "%d ", pt->content);
    pos += sprintf(buf + pos, "%ld ", (long)pt->content);

  }
  buf[pos] = '\0';
  return buf;
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

elemptr creaelem(/*int*/ void *valore) 
{
  elemptr ret = malloc(sizeof(elem));
  if (ret != NULL) {
    ret->next = NULL;
    ret->content = valore;
  }
  return ret;
}

int insert(/*int*/ void *val, listaptr l, int index) // inserisce a posizione index
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

  elemptr new = creaelem(val);
  if (new != NULL) {
    new->next = *el;
    *el = new;
    return 0;
  }

  return 1;
}

int test_insert(void) 
{
  int failures = 0;
  int retval = 0;
  char* result = NULL;
  listaptr lp = crealista();

  // primo inserimento in posizione 0
  insert((void*)1, lp, 0);
  result = stampaLista(lp);
  if (strcmp(result, "1 ") != 0) {
    failures += 1;
    fprintf(stderr, "expected: '%s' found: '%s'\n", "1 ", result);
  }

  // secondo inserimento in posizione 0 di un numero differente
  insert((void*)0, lp, 0);
  result = stampaLista(lp);
  if (strcmp(result, "0 1 ") != 0) {
    failures += 1;
    fprintf(stderr, "expected: '%s' found: '%s'\n", "0 1 ", result);
  }
  
  // terzo inserimento in posizione 1
  insert((void*)2, lp, 1);
  result = stampaLista(lp);
  if (strcmp(result, "0 2 1 ") != 0) {
    failures += 1;
    fprintf(stderr, "expected: '%s' found: '%s'\n", "0 2 1 ", result);
  }

  // quarto inserimento in posizione 5 il numero 10 (impossibile e risultato uguale) 
  retval = insert((void*)10, lp, 5);
  result = stampaLista(lp);
  if (retval != 1 && strcmp(result, "0 2 1 ") != 0) {
    failures += 1;
    fprintf(stderr, "expected: '%s' found: '%s'\n", "0 2 1 ", result);
  }

  // quinto inserimento in posizione intermedia
  insert((void*)3, lp, 2);
  result = stampaLista(lp);
  if (strcmp(result, "0 2 3 1 ") != 0) {
    failures += 1;
    fprintf(stderr, "expected: '%s' found: '%s'\n", "0 2 3 1 ", result);
  }

  // sesto inserimento in posizione finale (append)
  retval = insert(10, lp, 5);
  result = stampaLista(lp);
  if (retval != 1 && strcmp(result, "0 2 3 1 4 ") != 0) {
    failures += 1;
    fprintf(stderr, "expected: '%s' found: '%s'\n", "0 2 3 1 4 ", result);
  }

  // inizio test removeel
  retval = removeEl(lp, 4);
  result = stampaLista(lp);
  if(retval != 0 && strcmp(result, "0 2 3 1 ") != 0) 
  {
      failures += 1;
      fprintf(stderr, "expected: '%s' found: '%s'\n", "0 2 3 1 ", result);
  }

  retval = removeEl(lp, 0);
  result = stampaLista(lp);
  if(retval != 0 && strcmp(result, "2 3 1 ") != 0) 
  {
      failures += 1;
      fprintf(stderr, "expected: '%s' found: '%s'\n", "2 3 1 ", result);
  }

  retval = removeEl(lp, 2);
  retval = removeEl(lp, 1);
  retval = removeEl(lp, 0);
  result = stampaLista(lp);
  if(retval != 0 && strcmp(result, "") != 0) 
  {
      failures += 1;
      fprintf(stderr, "expected: '%s' found: '%s'\n", "", result);
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
  retval = indexesof(0, lp);
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
  val = 1;
  l = NULL;
  return NULL;
}

int test_list(void)
{
  int failures = 0;
  failures += test_crealista();
  failures += test_insert_removeel();
  failures =+ test_indexof();
  return failures;
}
