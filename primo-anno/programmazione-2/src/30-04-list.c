#include "30-04-list.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

listnodeptr createlistnode(long val)
{
    listnodeptr ret = malloc(sizeof(listnode));
    if(ret != NULL) {
        ret->val = val;
    }
    return ret;
}

listptr createlist()
{
    listptr ret = malloc(sizeof(list));
    if(ret != NULL) {
        ret->head = NULL;
    }
    return ret;
}

void insert(listptr l, long val)
{
    listnodeptr el = createlistnode(val);
    if(el != NULL) {
        el->next = l->head;
        l->head = el;
    }
}

int test_list()
{
    int failures = 0;
    listptr l = createlist();
    for(long i = 999; i >= 0; i--) {
        insert(l, i);
    }
    long j = 0;
    for(listnodeptr el = l->head; el != NULL; el = el->next, j++) {
        if(el->val != j) {
            failures += 1;
            fprintf(stderr, "error in testlist\n");
            break;
        }
    }
    return failures;
}