/* INSERIRE QUI EVENTUALI ALTRI #include <...> */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*  INSERIRE QUI EVENTUALI FUNZIONI AUSILIARIE (CON UN COMMENTO SIGNIFICATIVO IN TESTA) */
typedef struct listNode ListNode, *List;

struct listNode {
    char data;
    List next;
};

int compare(List l, int arr[], int size)
{
    List curr = l;
    for (int i = 0; i < size; i++)
    {
        if (curr == NULL) return 1;
        if (curr->data != arr[i]) return 1;
        curr = curr->next;
    }

    if (curr != NULL) return 1; // lista troppo lunga quindi ha valori in più 
    return 0;
}

void free_list(List l)
{
    while (l != NULL)
    {
        List tmp = l;
        l = l->next;
        free(tmp);
    }
}

/**
 * ALGORITMO:
 * data una stringa s, restituisci una lista contenente tutte e sole le cifre ('0'..'9') nell’ordine in cui compaiono in s.
 * Se s == NULL oppure non c’è nessuna cifra, restituisci NULL.
 * 
 * ESEMPI:
 * - NULL → NULL
 * - "" → NULL
 * - "a1b02Z" → [1,0,2]
 * - "abc" → NULL
 * Punti chiave: allocare solo quando il char è valido; lista vuota ⇒ NULL.
 */
List onlyDigitsToList(const char *s) 
{
    // la stringa non è modificabile perchè è const char
    if (s == NULL || *s == '\0') return NULL;
    
    List l = NULL;
    List curr = l;
    while (*s != '\0')
    {
        if (isdigit((unsigned char)s[0]))
        {
            List new_node = (List)malloc(sizeof(ListNode));
            new_node->data = s[0] - '0';
            new_node->next = NULL;
            
            if (curr == NULL)
            {
                l = new_node; 
                curr = new_node;
            }
            else
            {
                curr->next = new_node;
            }

            curr = curr->next;
        }
        
        s++;
    }

    return l;
}


/**
 * MAIN
 */
int main(void) 
{

    /* INSERIRE QUI IL CODICE */
    char *string = "a1b02Z";
    List l = onlyDigitsToList(string);

    int expected_result[] = {1, 0, 2};
    int result = compare(l, expected_result, 3);

    if (result)
        printf("TEST FAILED\n");
    else
        printf("TEST PASSED\n");

    free_list(l);
    return 0;
}
