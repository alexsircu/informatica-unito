#include <string.h>
#include <stdlib.h>
#include <stdio.h>

dynStringPtr createDynString(int capacity);                 // create
void append(dynStringPtr s, char* s2);                      // append
char* toCharStar(dynStringPtr p);                           // get the string
void deleteDynStr(dynStringPtr p);                          // free memory
void resetDynStr(dynStringPtr p);                           // reset the content
int test_createDynString(void);
void test_dynString_module(void);

typedef struct 
{
    char* content;                                          // dynamically allocated
    int capacity;                                           // max number of chars      
    int last;                                               // first free space
    int dynamic;                                            // dynamically allocated     
} dynString, *dynStringPtr;

int main (void)
{
    test_dynString_module();
}

dynStringPtr createDynString(int capacity) 
{   

    if (capacity <= 0) return NULL;

    dynStringPtr p = malloc(sizeof(dynString));

    if (p) 
    {
        p->content = malloc(sizeof(char) * capacity);
        
        if (!p->content)
        {
            free(p);
            return NULL;
        }
        
        p->capacity = capacity;
        p->last = 0;                                        
    }

    return p;
}

void append(dynStringPtr s, char* s2)
{
    if (!s || !s2) return;
    int s2Length = strlen(s2);

    if (s->capacity >= s2Length + s->last)
    {
        strncpy(s->content + s->last, s2, s2Length);
        s->last += s2Length;
    } 
    else 
    {
        char* new = realloc(s->content, s->capacity * 2);
        if (!new) printf("Error reallocating space\n");
    }
}

void resetDynStr(dynStringPtr p)
{
    if (p) p->last = 0;
}

void deleteDynStr(dynStringPtr p)
{
    if (p) 
    {
        if (p->content) free(p->content); 
        free(p);
    } 
}

// TEST FUNCTIONS
void test_dynString_module(void)
{
    printf("Testing test dynString module\n");
    int failures = 0;
    failures += test_createDynString();

    if (failures > 0)
        printf("There are some errors, number of failures %d\n", failures);
    else 
        printf("Test passed");
}

int test_createDynString(void) 
{
    printf("Testing createDynString function\n");
    dynStringPtr val = createDynString(-10);

    if (!val) 
        return 1;

    return 0;
}
