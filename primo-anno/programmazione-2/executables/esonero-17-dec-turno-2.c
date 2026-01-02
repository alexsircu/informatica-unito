/* INSERIRE QUI EVENTUALI ALTRI #include <...> */
/* INSERT HERE MORE #include <...> IF NEEDED */
#include <stdio.h>
#include <stdlib.h>

#define LEFT_DATA_ARR_LENGTH 4
#define RIGHT_DATA_ARR_LENGTH 5

/* INSERIRE QUI EVENTUALI FUNZIONI AUSILIARIE */
/* INSERT HERE AUXILIARY FUNCTIONS IF NEEDED */
typedef struct listNode ListNode, *List;

struct listNode {
    int data;
    List next;
};

List insert_node(List l, int val)
{
    List new_node = (List)malloc(sizeof(ListNode));
    new_node->data = val;
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

int compare_lists(List left, List right, int expected_left[], int expected_right[])
{
    List current_left = left;
    List current_right = right;

    for (int i = 0; i < LEFT_DATA_ARR_LENGTH; i++)
    {
        if (current_left != NULL)
        {
            if (expected_left[i] != current_left->data) return 0;
            current_left = current_left->next;
        }
    }

    for (int i = 0; i < RIGHT_DATA_ARR_LENGTH; i++)
    {
        if (current_right != NULL)
        {
            if (expected_right[i] != current_right->data) return 0;
            current_right = current_right->next;
        }
    }

    return 1;
}

void free_list(List l)
{
    List current_list = l;
    while (current_list != NULL)
    {
        List tmp = current_list;
        current_list = current_list->next;
        free(tmp);
    }
}

/**
 * Modifica due liste di caratteri l e r, cercando l'**ultima** occorrenza di
 * val in l (nodo nl) e la **prima** occorrenza di val in r (nodo nr), facendo
 * un “crossover” tra le liste: dopo l’esecuzione, il nodo nr dovrà puntare
 * alla parte di lista che prima seguiva nl, e il nodo nl dovrà puntare alla
 * parte di lista che prima seguiva nr.
 *
 * ESEMPI:
 * (1) date l=[0], r=[0] e val=0, produce l=[0] e r=[0]
 * (2) date l=[0,1,2,3], r=[6,7,1,4,5] e val=1, produce l=[0,1,4,5] e r[6,7,1,2,3]
 * (3) date l=[3,4,3,5], r=[0,3,1,3,2] e val=3, produce l=[3,4,3,1,3,2] e r[0,3,5]
 * 
 * NOTA: è garantito che val occorre in entrambe le liste almeno una volta
 * NOTA: questa funzione compare negli errori di compilazione come "student_crossover"
 * NOTA: questa funzione viene testata indipendentemente dal vostro main
 * IMPORTANTE: cercate sempre di far compilare il vostro codice per poter vedere il
 * risultato dei test, anche a costo di commentare parte del codice di questa funzione
 *
 * <ENGLISH VERSION>
 * 
 * Modifies two lists of character l and r by searching for the **last** occurrence
 * of val in l (node nl) and the **first** occurrence of val in r (node nr), and
 * performing a “crossover” between the lists: after execution, node nr must point
 * to the portion of the list that originally followed nl, and node nl must point
 * to the portion of the list that originally followed nr.
 *
 * EXAMPLES:
 * (1) given l=[0], r=[0] and val=0, produces l=[0] and r=[0]
 * (2) given l=[0,1,2,3], r=[6,7,1,4,5] and val=1, produces l=[0,1,4,5] and r[6,7,1,2,3]
 * (3) given l=[3,4,3,5], r=[0,3,1,3,2] and val=3, produces l=[3,4,3,1,3,2] and r[0,3,5]
 *
 * NOTE: it is guaranteed that val occurs in both lists at least once
 * NOTE: this function appears in compilation errors as "student_crossover"
 * NOTE: this function is tested independently of your main
 * IMPORTANT: always try to make your code compile so that you can see the test
 * results, even if that means commenting out part of the code of this function
 */
void crossover(List left, List right, int val) 
{

    /* INSERIRE QUI IL CODICE */
    /* INSERT YOUR CODE HERE */
    
    List current_l = left;
    List current_r = right;
    List nl_next = NULL;
    List nr_next = NULL;
    List nl = NULL;
    List nr = NULL;
    
    while (current_r != NULL)
    {
        if (val == current_r->data)
        {
            // prima occorrenza
            nr = current_r;
            nr_next = current_r->next;
            
            while (current_l != NULL)
            {
                if (val == current_l->data)
                {
                    // ultima occorrenza
                    nl = current_l;
                    nl_next = current_l->next;
                }
        
                current_l = current_l->next;
            }
            
            nr->next = nl_next;
            nl->next = nr_next;
            break;
        }

        current_r = current_r->next;
    }
}

/**
 * Invoca la funzione crossover su alcuni casi a scelta per testarne la correttezza.
 * Se la funzione crossover è corretta, come ultima cosa deve stampare "TEST PASSED\n".
 * Se invece la funzione non risulta corretta, deve stampare "TEST FAILED\n".
 * 
 * NOTA: questa funzione compare negli errori di compilazione come "student_main"
 * NOTA: il main viene testato indipendentemente dalla vostra funzione crossover
 * IMPORTANTE: cercate sempre di far compilare il vostro codice per poter vedere il
 * risultato dei test, anche a costo di commentare parte del codice di questa funzione
 *
 * <ENGLISH VERSION>
 * 
 * Invokes the crossover function on some selected test cases to verify its correctness.
 * If the crossover function is correct, as the final step it must print "TEST PASSED\n".
 * If instead the function is not correct, it must print "TEST FAILED\n".
 *
 * NOTE: this function appears in compilation errors as "student_main"
 * NOTE: the main is tested independently of your crossover function
 * IMPORTANT: always try to make your code compile so that you can see the test
 * results, even if that means commenting out part of the code of this function
 */
int main(void) 
{
    
    /* INSERIRE QUI IL CODICE */
    /* INSERT YOUR CODE HERE */

    List left = NULL;
    List right = NULL;
    int left_data[] = {0,1,2,3};
    int right_data[] = {6,7,1,4,5};
    int val = 1;
    int expected_left[] = {0,1,4,5};
    int expected_right[] = {6,7,1,2,3};

    for (int i = 0; i < LEFT_DATA_ARR_LENGTH; i++)
    {
        left = insert_node(left, left_data[i]);
    }

    for (int i = 0; i < RIGHT_DATA_ARR_LENGTH; i++)
    {
        right = insert_node(right, right_data[i]);
    }

    crossover(left, right, val);
    
    int result = compare_lists(left, right, expected_left, expected_right);
    
    if (result)
        printf("TEST PASSED\n");
    else
       printf("TEST FAILED\n"); 
    
    free_list(left);
    free_list(right);
    return 0;
}
