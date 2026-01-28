/* INSERIRE QUI EVENTUALI ALTRI #include <...> */
#include <stdio.h>
#include <stdlib.h>

/*  INSERIRE QUI EVENTUALI FUNZIONI AUSILIARIE (CON UN COMMENTO SIGNIFICATIVO IN TESTA) */
typedef struct listNode ListNode, *List;

struct listNode {
    char data;
    List next;
};

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

List create_list(char *str)
{

    List l = NULL;
    List curr = NULL;
    while (*str != '\0')
    {
        List new_node = (List)malloc(sizeof(ListNode));
        if (new_node == NULL) 
        {
            free_list(l);
            return;
        }

        new_node->data = *str;
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

        str++;
    }

    return l;
}

int compare(List l, char *str)
{
    if (str == NULL) return 1;

    List curr = l;
    while (*str != '\0')
    {
        if (curr == NULL) return 1;
        if (curr->data != *str) return 1;
        curr = curr->next;
        str++;
    }
    
    if (curr != NULL) return 1;
    return 0;
}

/**
 * ALGORITMO:
 * data una lista di caratteri, restituisci una nuova lista ottenuta da l eliminando i “run” consecutivi,
 * cioè comprimendo ripetizioni adiacenti in un singolo nodo.
 * 
 * ESEMPI:
 * - l=[] -> []
 * - l=[a] -> [a]
 * - l=[a, a, a, b, b, c, a, a] -> [a, b, c, a]
 * - l=[x, y, y, z] -> [x, y, z]
 */
List removeRuns(List l) 
{
    if (l == NULL) return NULL;

    List curr = l;
    List prev = NULL;

    while (curr != NULL)
    {
        if (prev != NULL && prev->data == curr->data)
        {
            // curr è un duplicato consecutivo: lo elimino
            List tmp = curr;
            curr = curr->next;       // avanzo PRIMA di free
            prev->next = curr;       // "salto" il nodo eliminato
            free(tmp);
        }
        else
        {
            // curr è il primo di un run (o non è duplicato): lo tengo
            prev = curr;
            curr = curr->next;
        }
    }

    return l;
}

/**
 * MAIN
 */
int main(void) 
{
    /* INSERIRE QUI IL CODICE */
    List l = NULL;
    List f = NULL;
    char *str = "aaabbcaa";
    char *exp_str = "abca";

    l = create_list(str);
    f = removeRuns(l);
    int result = compare(f, exp_str);

    if (result)
    {
        printf("TEST FAILED\n");
    }
    else
    {
        printf("TEST PASSED\n");
    }

    free_list(l);
    free_list(f);
    return 0;
}
