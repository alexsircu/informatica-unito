#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode IntTreeNode, *IntTree;

struct treeNode {
    IntTree left;
    IntTree right;
    int data;
};


/**
 * Dato un albero binario tree, e due numeri interi min e max, restituisce la somma
 * di tutti gli elementi che si trovano ad un livello >= min e <= max. Si assuma che il livello della radice sia 0.
 *
 * ESEMPI: dato
 *
 *      1
 *     / \
 *    2   3
 *  / \
 * 4   5
 * 
 * 1)  per min = 0  e max = 4 restituisce 15   
 * 2)  per min = 1  e max = 3 restituisce 14  
 * 3)  per min = 2  e max = 2 restituisce 9
 * 4)  per min = 3  e max = 2 restituisce 0
 * 5)  per min = 2  e max = -5 restituisce 0
 * 6)  per min = 6 e max = 7 restituisce 0                    
 * 7)  tree = NULL, restituisce 0 
 *
 * int sumMinMax (IntTree tree, int min, int max);
 * realizzarne una implementazione RICORSIVA.
*/

int sumMinMaxRec(IntTree tree, int min, int max, int level)
{
    if (tree == NULL) return 0;
    if (level > max) return 0;
    
    int sum = 0;
    if (level >= min && level <= max) sum = tree->data; // elemento

    sum += sumMinMaxRec(tree->left, min, max, level + 1);
    sum += sumMinMaxRec(tree->right, min, max, level + 1);
    return sum;
}

int sumMinMax(IntTree tree, int min, int max)
{
    if (tree == NULL) return 0;
    if (min > max) return 0;
    return sumMinMaxRec(tree, min, max, 0);
}