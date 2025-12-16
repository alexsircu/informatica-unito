/* INSERIRE QUI EVENTUALI ALTRI #include <...> */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

/*  INSERIRE QUI EVENTUALI FUNZIONI AUSILIARIE (CON UN COMMENTO SIGNIFICATIVO IN TESTA) */
typedef struct listNode ListNode, *List;

struct listNode {
    char data;
    List next;
};

bool confront_list(List l, char *expected)
{
    List current = l;
    int i = 0;

    while(current != NULL && expected[i] != '\0')
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
    while(current != NULL)
    {
        printf("%d", current->data);
        current = current->next;
    }
}

void free_list(List l)
{
    List current = l;
    while(current != NULL)
    {
        List tmp = current;
        current = current->next;
        free(tmp);
    }
}

/**
 * Data una stringa s, restituisce una lista di caratteri che contiene tutti
 * e soli i caratteri alfabetici maiuscoli (A - Z) trasformati in minuscoli
 * (a - z) della stringa s nell'ordine in cui occorrono in s.
 *
 * Non considera l'eventualità che la malloc fallisca.
 * Se s == NULL, restituisce NULL.
 *
 * ESEMPI (rappresentando le liste senza separare i caratteri, per compattezza):
 * (1) data s == NULL  restituisce NULL
 * (2) data s == "" restituisce NULL
 * (3) data s == "A" restituisce [a]
 * (4) data s == "AZbCuu12R" restituisce [a,z,c,r]
 *
 * NOTA: questa funzione compare negli errori di compilazione come "student_stringToList"
 * NOTA: questa funzione viene testata indipendentemente dal vostro main
 * IMPORTANTE: cercate sempre di far compilare il vostro codice per poter vedere il
 * risultato dei test, anche a costo di commentare parte del codice di questa funzione
 */
List stringToList(char *s) {
    if (s == NULL || *s == '\0') return NULL;

    // dichiaro le liste (head e tail)
    List list = NULL;
    List tmp_list = NULL;

    // ciclo sulla stringa
    while (*s != '\0')
    {        
        // se maiuscola
        if (isupper(*s))
        {
            ListNode* node = (ListNode*)malloc(sizeof(ListNode));
            node->data = (char)tolower(*s);
            node->next = NULL;

            if (list == NULL)
            {
                list = node;
                tmp_list = node;
            }
            else
            {
                tmp_list->next = node;
                tmp_list = node;
            }
        }

        s++;
    }
  
    return list;
}


/**
 * Invoca la funzione stringToList su alcuni casi a scelta per testarne la correttezza.
 * Se la funzione stringToList è corretta, come ultima cosa deve stampare "TEST PASSED\n".
 * Se invece la funzione non risulta corretta, deve stampare "TEST FAILED\n".
 *
 * NOTA: questa funzione compare negli errori di compilazione come "student_main"
 * NOTA: il main viene testato indipendentemente dalla vostra funzione stringToList
 * IMPORTANTE: cercate sempre di far compilare il vostro codice per poter vedere il
 * risultato dei test, anche a costo di commentare parte del codice di questa funzione
 */
int main() {

    /* INSERIRE QUI IL CODICE */
    char *s = "AZbCuu12R";
    List l = stringToList(s);
    char *expected = "azcr";
    bool passed = confront_list(l, expected);
    print_list(l);

    if(passed)
        printf("TEST PASSED\n");
    else
        printf("TEST FAILED\n");
    
    free_list(l);
    return 0;
}
