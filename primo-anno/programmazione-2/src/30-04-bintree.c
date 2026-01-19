#include "30-04-bintree.h"
#include "30-04-list.h"

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#define SIZE 1000

binnodeptr createtree()
{
    bintreeptr ret = malloc(sizeof(binnode));
    if (ret != NULL) ret->root = NULL;
    return ret;
}

binnodeptr createbinnode(long val)
{
    binnodeptr ret = malloc(sizeof(binnode));
    if(ret != NULL) {
        ret->val = val;
    }
    return ret;
}

binnodeptr convertric(int *elements, int start, int end)
{
    if (start > end) return NULL;

    int index = (start + end) / 2;
    binnodeptr ret = createbinnode(elements[index]);
    ret->left = convertric(elements, start, index - 1);
    ret->right = convertric(elements, index + 1, end);

    return ret;
}

void printtree(binnodeptr n)
{
    if (n != NULL)
    {
        printtree(n->left);
        fprintf(stderr, "%ld\n", n->val);
        printtree(n->right);
    }
}

binnodeptr converttotree(int *elements)
{
    bintreeptr ret = createtree();
    ret->root = convertric(elements, 0, SIZE - 1);
    return ret;
}

int test_bintree()
{
    int failures = 0;
    listptr l = createlist();
    for(long i = SIZE - 1; i >= 0; i--) {
        insert(l, i);
    }

    int *myarr = malloc(sizeof(int) * SIZE); // array di 1000
    int i = 0;
    listnodeptr curr = l->head;
    while (curr != NULL)
    {
        myarr[i++] = curr->val;
        curr = curr->next;
    }
    
    bintreeptr tree = converttotree(myarr);
    //fprintf(stderr, "radice: %ld\n", tree->root->val);
    printtree(tree->root);

    return failures;
}