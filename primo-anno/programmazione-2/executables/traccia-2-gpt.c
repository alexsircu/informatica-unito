/* INSERIRE QUI EVENTUALI ALTRI #include <...> */
#include <stdio.h>
#include <stdlib.h>

/*  INSERIRE QUI EVENTUALI FUNZIONI AUSILIARIE (CON UN COMMENTO SIGNIFICATIVO IN TESTA) */
typedef struct listNode ListNode, *List;

struct listNode {
    char data;
    List next;
};

List create_list(char *s)
{
    if (s == NULL) return NULL;

    List l = NULL;
    List curr = NULL;
    while (*s != '\0')
    {
        List new_node = (List)malloc(sizeof(ListNode));
        if (!new_node) 
        {
            free(new_node);
            return NULL;
        }
        
        new_node->data = *s;
        new_node->next = NULL;

        if (l == NULL)
        {
            l = new_node;
            curr = new_node;
        }
        else
        {
            curr->next = new_node;
            curr = curr->next;
        }

        s++;
    }

    return l;
}

int compare(List f, char *expected)
{
    if (expected == NULL) return 1;
    if (*expected == '\0') return (f != NULL); // se f != NULL allora è 1 altrimenti è 0
    if (f == NULL) return 1;

    List curr = f;
    while (*expected != '\0')
    {
        if (curr == NULL) return 1;
        if (curr->data != *expected) return 1;
        curr = curr->next;
        expected++;
    }
    
    if (curr != NULL) return 1; // lista non finita ma stringa finita, non sono uguali
    return 0;
}

void free_list(List l)
{
    if (l == NULL) return;

    List curr = l;
    while (curr != NULL)
    {
        List tmp = curr;
        curr = curr->next;
        free(tmp);
    }
}

/**
 * ALGORITMO:
 * restituisci il più lungo prefisso di l tale che, per ogni posizione i considerata, vale:
 * se r ha l'i-esimo nodo, allora l[i] != r[i]
 * se r finisce prima, puoi continuare a prendere da l fino alla fine (perchè non esiste vincolo)
 * 
 * ESEMPI:
 * - l=[] r=[] → []
 * - l=[p,i,p,p,o] r=[p,i,p,p,o] → []
 * - l=[s,u,p,e,r] r=[p,i,p,p,o] → [s,u] (si blocca quando p==p)
 * - l=[a,b,c] r=[x] → [a,b,c] (vincolo solo sulla prima posizione)
 */
List antiPrefix2(List l, List r) 
{
    if (l == NULL) return NULL;

    List currL = l;
    List currR = r;
    List f = NULL;
    List currF = NULL;
    
    while (currL != NULL)
    {
        if (currR != NULL && currL->data == currR->data) break;

        List new_node = (List)malloc(sizeof(ListNode));
        new_node->data = currL->data;
        new_node->next = NULL;

        if (f == NULL)
        {
            f = new_node;
            currF = new_node;
        }
        else
        {
            currF->next = new_node;
            currF = currF->next;
        }

        currL = currL->next;
        if (currR != NULL)
            currR = currR->next;
    }

    return f;
}


/**
 * MAIN
 */
int main(void) 
{
    /* INSERIRE QUI IL CODICE */

    List l = NULL;
    List r = NULL;
    List f = NULL;

    char *str1 = "super";
    char *str2 = "pippo";

    l = create_list(str1);
    r = create_list(str2);
    f = antiPrefix2(l, r);

    char *expected = "su";
    int result = compare(f, expected);

    if (result)
    {
        printf("TEST FAILED\n");
    }
    else
    {
        printf("TEST PASSED\n");
    }

    free_list(l);
    free_list(r);
    free_list(f);
    return 0;
}
