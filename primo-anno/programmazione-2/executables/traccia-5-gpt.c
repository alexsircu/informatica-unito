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
    if (*str == '\0') return NULL;
    
    List head = NULL;
    List tail = NULL;
    while (*str != '\0')
    {
        List new_node = (List)malloc(sizeof(ListNode));
        if (new_node == NULL)
        {
            free_list(head);
            return NULL;
        }

        new_node->data = *str;
        new_node->next = NULL;

        if (head == NULL)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            tail->next = new_node;
            tail = tail->next;
        }

        str++;
    }

    return head;
}

int compare(List l, char *str)
{
    if (l == NULL || *str == '\0') return 1;

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
 * come il tuo crossover, ma invece di usare i nodi che contengono val, usi i nodi PRECEDENTI:
 * - in l: trova il nodo precedente la prima occorrenza di val
 * - in r: trova il nodo che precede l'ultima occorrenza di val 
 * Poi fai il crossover sui next di quei predecessori
 * Vincoli: è garantito che:
 * - val compare in entrambe
 * - e non è mai nel primo nodo di entrambe (quindi il predecessore esiste)
 * 
 * ESEMPIO:
 * - l=[a,b,c,d] r=[g,h,b,e,f] val='b'
 * - predL = a, predR = h
 * - dopo: l=[a,b,e,f] r=[g,h,b,c,d] (uguale al caso base, ma devi arrivarci via predecessori)
 */
void crossoverPrev(List l, List r, char val) 
{
    if (l == NULL || r == NULL) return;

    List curr_l = l;
    List curr_r = r;

    List prev_l = NULL;
    List prev_r = NULL;

    while (curr_l != NULL)
    {
        prev_l = curr_l;
        
        if (curr_l->next != NULL)
            if (curr_l->next->data == val) break;

        curr_l = curr_l->next;
    }
    
    while (curr_r != NULL)
    {   
        if (curr_r->next != NULL)
            if (curr_r->next->data == val) prev_r = curr_r;

        curr_r = curr_r->next;
    }

    if (prev_l == NULL || prev_r == NULL) return;

    List tmp = prev_l->next; 
    prev_l->next = prev_r->next;
    prev_r->next = tmp;
}

/**
 * MAIN
 */
int main(void) 
{
    /* INSERIRE QUI IL CODICE */
    List l = NULL;
    List r = NULL;
    char *str_l = "abcd";
    char *str_r = "ghbebf";
    char val = 'b';
    char *exp_l = "abef";
    char *exp_r = "ghbcd";

    l = create_list(str_l);
    r = create_list(str_r);

    crossoverPrev(l, r, val);
    int result_l = compare(l, exp_l);
    int result_r = compare(r, exp_r);
 
    if (result_l || result_r)
        printf("TEST FAILED\n");
    else
        printf("TEST PASSED\n");

    free_list(l);
    free_list(r);
    return 0;
}
