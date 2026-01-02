/* INSERIRE QUI EVENTUALI ALTRI #include <...> */
/* INSERT HERE MORE #include <...> IF NEEDED */
#include <stdio.h>
#include <stdlib.h>

/* INSERIRE QUI EVENTUALI FUNZIONI AUSILIARIE */
/* INSERT HERE AUXILIARY FUNCTIONS IF NEEDED */
typedef struct ListNode ListNode, *List;

struct ListNode {
    char info;               
    List next;    
};

List insert_node(List l, char c)
{
    List new_node = (List)malloc(sizeof(ListNode));
    new_node->info = c;
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

int compare_list(List left, List right, char *expected_left, char *expected_right)
{
    List current_left = left;
    List current_right = right;

    for (int i = 0; expected_left[i] != '\0'; i++)
    {
        if (current_left->info != expected_left[i]) return 0;
        current_left = current_left->next;
    }

    for (int i = 0; expected_right[i] != '\0'; i++)
    {
        if (current_right->info != expected_right[i]) return 0;
        current_right = current_right->next;
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

/* Definizione del tipo List come puntatore al primo nodo */
/* INSERIRE QUI EVENTUALI ALTRI #include <...> */
/* INSERT HERE MORE #include <...> IF NEEDED */

/* INSERIRE QUI EVENTUALI FUNZIONI AUSILIARIE */
/* INSERT HERE AUXILIARY FUNCTIONS IF NEEDED */

/**
 * Modifica due liste di caratteri l e r, cercando la prima occorrenza di
 * val in l (nodo nl) e l’**ultima** occorrenza di val in r (nodo nr), facendo
 * un “crossover” tra le liste: dopo l’esecuzione, il nodo nr dovrà puntare
 * alla parte di lista che prima seguiva nl, e il nodo nl dovrà puntare alla
 * parte di lista che prima seguiva nr.
 *
 * ESEMPI (rappresentando le liste senza separare i caratteri, per compattezza):
 * (1) date l=[a], r=[a] e val='a', produce l=[a] e r=[a]
 * (2) date l=[a,b,c,d], r=[g,h,b,e,f] e val='b', produce l=[a,b,e,f] e r[g,h,b,c,d]
 * (3) date l=[a,d,b,d,c], r=[d,e,d,f] e val='d', produce l=[a,d,f] e r[d,e,d,b,d,c]
 * 
 * NOTA: è garantito che val occorre in entrambe le liste almeno una volta
 * NOTA: questa funzione compare negli errori di compilazione come "student_crossover"
 * NOTA: questa funzione viene testata indipendentemente dal vostro main
 * IMPORTANTE: cercate sempre di far compilare il vostro codice per poter vedere il
 * risultato dei test, anche a costo di commentare parte del codice di questa funzione
*/

void crossover (List l, List r, char c) 
{
    /* INSERIRE QUI IL CODICE */
    /* INSERT YOUR CODE HERE */

    List nl = NULL;
    List nr = NULL;
    List nl_next = NULL;
    List nr_next = NULL;
    List current_left = l;
    List current_right = r;

    // scorrere sulla lista l per trovare la prima occorrenza e fare break
    while (current_left != NULL)
    {
        if (current_left->info == c) 
        {
            nl = current_left;
            nl_next = current_left->next;
            break;
        }

        current_left = current_left->next;
    }

    // scorrere sulla lista r per trovare l'ultima occorrenza
    while (current_right != NULL)
    {
        if (current_right->info == c)
        {
            nr = current_right;
            nr_next = current_right->next;
        }

        current_right = current_right->next;
    }

    nr->next = nl_next;
    nl->next = nr_next;
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
    List left = NULL;
    List right = NULL;
    char *left_string = "abcd";
    char *right_string = "ghbef";
    char character = 'b';
    char *expected_left_string = "abef";
    char *expected_right_string = "ghbcd";

    for (int i = 0; left_string[i] != '\0'; i++)
    {
        left = insert_node(left, left_string[i]);
    }

    for (int i = 0; right_string[i] != '\0'; i++)
    {
        right = insert_node(right, right_string[i]);
    }

    crossover(left, right, character);

    int result = compare_list(left, right, expected_left_string, expected_right_string);

    if (result)
        printf("TEST PASSED\n");
    else
        printf("TEST FAILED");

    free_list(left);
    free_list(right);
    return 0;
}
