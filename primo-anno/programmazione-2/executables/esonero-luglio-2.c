/* INSERIRE QUI EVENTUALI ALTRI #include <...> */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* INSERIRE QUI EVENTUALI FUNZIONI AUSILIARIE */

typedef struct listNode ListNode, *List;

struct listNode {
    char data;
    List next;
};

List insert_node(List l, char s)
{
    List new_node = (List)malloc(sizeof(ListNode));
    new_node->data = s;
    new_node->next = NULL;
    if (l == NULL) return new_node;
    List current = l;

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = new_node;
    return l;
}

bool test_confront(List l, char *expected)
{
    List current = l;
    int i = 0;

    while (current != NULL && expected[i] != '\0')
    {
        if (current->data != expected[i]) return false;
        current = current->next;
        i++;
    }

    if (current == NULL && expected[i] == '\0') return true;
    return false;
}

void print_list(List l)
{
    List current = l;
    while (current != NULL)
    {
        printf("%d", current->data);
        current = current->next;
    }
}

void free_list(List l)
{
    List current = l;
    while (current != NULL)
    {
        List tmp = current;
        current = current->next;
        free(tmp);
    }
}

/**
 * Date due liste di caratteri l ed r, restituire una nuova lista p (senza
 * modificare le liste l ed r) che contenga il più lungo prefisso di l per
 * cui nessun suo carattere ha un carattere uguale nella posizione
 * corrispondente di r.
 * 
 * Si definisce "prefisso" di una lista una qualunque sotto-lista di nodi dall'inizio.
 * Non considera l'eventualità che la malloc fallisca.
 *
 * ESEMPI (rappresentando le liste senza separare i caratteri, per compattezza):
 * (1) date l=[] e s=[], restituisce p=[]
 * (2) date l=[] e s=[p,i,p,p,o], restituisce p=[]
 * (3) date l=[p,i,p,p,o] e s=[], restituisce p=[p,i,p,p,o]
 * (4) date l=[p,i,p,p,o] e s=[p,i,p,p,o], restituisce p=[]
 * (5) date l=[s,u,p,e,r,p,i,p,p,o] e s=[p,l,u,t,o], restituisce p=[s,u,p,e,r,p,i,p,p,o]
 * (6) date l=[p,l,u,t,o] e s=[s,u,p,e,r,p,i,p,p,o], restituisce p=[p,l,u,t,o]
 * (7) date l=[s,u,p,e,r,p,i,p,p,o] e s=[p,i,p,p,o], restituisce p=[s,u], perché la p seguente è in comune
 * (8) date l=[p,i,p,p,o] e s=[s,u,p,e,r,p,i,p,p,o], restituisce p=[p,i], perché la p seguente è in comune
 * 
 * NOTA: questa funzione compare negli errori di compilazione come "student_antiPrefix"
 * NOTA: questa funzione viene testata indipendentemente dal vostro main
 * IMPORTANTE: cercate sempre di far compilare il vostro codice per poter vedere il
 * risultato dei test, anche a costo di commentare parte del codice di questa funzione
 */
List antiPrefix(List l, List r) {

    /* INSERIRE QUI IL CODICE */
    if (l == NULL) return NULL;

    List tmp_l = l;
    List tmp_r = r;
    List p = NULL;
    List tmp_p = NULL;

    while (tmp_l != NULL)
    {
        // se r ha nodo e se i dati sono differenti
        if (tmp_r != NULL && tmp_l->data != tmp_r->data)
        {
            List node = (List)malloc(sizeof(ListNode));
            node->data = tmp_l->data;
            node->next = NULL;

            if (p == NULL)
            {
                p = node;
                tmp_p = node;
            }
            else
            {
                tmp_p->next = node;
                tmp_p = node;
            }

            tmp_r = tmp_r->next;
        }
        else
        {
            if (tmp_r != NULL) break;
            List node = (List)malloc(sizeof(ListNode));
            node->data = tmp_l->data;
            node->next = NULL;

            if (p == NULL)
            {
                p = node;
                tmp_p = node;
            }
            else
            {
                tmp_p->next = node;
                tmp_p = node;
            }
        }

        tmp_l = tmp_l->next;      
    }

    return p;
}

/**
 * Invoca la funzione antiPrefix su alcuni casi a scelta per testarne la correttezza.
 * Se la funzione antiPrefix è corretta, come ultima cosa deve stampare "TEST PASSED\n".
 * Se invece la funzione non risulta corretta, deve stampare "TEST FAILED\n".
 * 
 * NOTA: questa funzione compare negli errori di compilazione come "student_main"
 * NOTA: il main viene testato indipendentemente dalla vostra funzione antiPrefix
 * IMPORTANTE: cercate sempre di far compilare il vostro codice per poter vedere il
 * risultato dei test, anche a costo di commentare parte del codice di questa funzione
 */
int main() {
    char *string1 = "superpippo";
    char *string2 = "pippo";
    List l = NULL;
    List r = NULL;

    for(int i = 0; string1[i] != '\0'; i++)
    {
        l = insert_node(l, string1[i]);
    }

    for(int i = 0; string2[i] != '\0'; i++)
    {
        r = insert_node(r, string2[i]);
    }

    List p = antiPrefix(l, r);
    print_list(p);
    char *expected = "su";
    bool passed = test_confront(p, expected);

    if(passed)
        printf("TEST PASSED\n");
    else
        printf("TEST FAILED\n");
    
    free_list(l);
    free_list(r);
    free_list(p);
    return 0;
}
