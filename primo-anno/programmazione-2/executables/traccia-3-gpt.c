/* INSERIRE QUI EVENTUALI ALTRI #include <...> */
#include <stdio.h>
#include <stdlib.h>

/*  INSERIRE QUI EVENTUALI FUNZIONI AUSILIARIE (CON UN COMMENTO SIGNIFICATIVO IN TESTA) */
typedef struct listNode ListNode, *List;

struct listNode {
    char data;
    List next;
};

List create_list(char *str)
{
    if (str == NULL) return NULL;

    List l = NULL;
    List curr = NULL;
    while (*str != '\0')
    {
        List new_node = (List)malloc(sizeof(ListNode));
        if (new_node == NULL) 
        {
            free_list(l); 
            return NULL;
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

int compare(List less, List ge, char *str_less, char *str_ge)
{
    if (str_less == NULL || str_ge == NULL) return 1;
    if (*str_less == '\0') return (less != NULL);
    if (*str_ge == '\0') return (ge != NULL);

    List curr_less = less;
    List curr_ge = ge;
    while (*str_less != '\0')
    {
        if (curr_less == NULL) return 1;
        if (curr_less->data != *str_less) return 1;
        curr_less = curr_less->next;
        str_less++;
    }

    while (*str_ge != '\0')
    {
        if (curr_ge == NULL) return 1;
        if (curr_ge->data != *str_ge) return 1;
        curr_ge = curr_ge->next;
        str_ge++;
    }

    if (curr_less != NULL || curr_ge != NULL) return 1;
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
 * *less: nodi con data < pivot
 * *ge: nodi con data >= pivot mantenendo l'ordine relativo originale (stable)
 * Non modificare l. Se l == NULL, entrambe devono diventare NULL.
 * 
 * ESEMPI: (pivot = 'm'):
 * - l=[a,m,z,b] -> less=[a,b], ge=[m,z]
 * - l=[] -> less=[], ge=[]
 */
void splitByPivot(List l, char pivot, List *less, List *ge) 
{
    *less = NULL;
    *ge = NULL;
    if (l == NULL) return;

    List curr_l = l;
    List curr_less = *less;
    List curr_ge = *ge;
    while (curr_l != NULL)
    {
        if (curr_l->data < pivot)
        {
            // dentro less
            List new_node = (List)malloc(sizeof(ListNode));
            if (new_node == NULL) 
            {
                free_list(*less);
                free_list(*ge);
                *less = NULL;
                *ge = NULL;
                return;
            }

            new_node->data = curr_l->data;
            new_node->next = NULL;

            if (*less == NULL)
            {
                *less = new_node;
                curr_less = new_node;
            }
            else
            {
                curr_less->next = new_node;
                curr_less = curr_less->next;
            }
        }
        else
        {
            // dentro ge
            List new_node = (List)malloc(sizeof(ListNode));
            if (new_node == NULL) return;

            new_node->data = curr_l->data;
            new_node->next = NULL;

            if (*ge == NULL)
            {
                *ge = new_node;
                curr_ge = new_node;
            }
            else
            {
                curr_ge->next = new_node;
                curr_ge = curr_ge->next;
            }
        }

        curr_l = curr_l->next;
    }
}


/**
 * MAIN
 */
int main(void) 
{
    /* INSERIRE QUI IL CODICE */
    List l = NULL;
    List less = NULL;
    List ge = NULL;
    char pivot = 'm';
    char *str = "amzb";

    l = create_list(str);
    char *expected_less = "ab";
    char *expected_ge = "mz";

    splitByPivot(l, pivot, &less, &ge);

    int result = compare(less, ge, expected_less, expected_ge);

    if (result) 
        printf("TEST FAILED\n");
    else
        printf("TEST PASSED\n");

    free_list(l);
    free_list(less);
    free_list(ge);
    return 0;
}
