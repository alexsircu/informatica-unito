#include <stdio.h>
#include <stdlib.h>

typedef struct charTreeNode CharTreeNode, *CharTree;
struct charTreeNode {
    CharTree left;
    char data;
    CharTree right;
};

/* =================== */
/* Funzioni ausiliarie */
/* =================== */

/* Crea un nuovo nodo */
CharTree new_node(char c)
{
    CharTree n = malloc(sizeof(CharTreeNode));
    if (!n) return NULL;
    n->data = c;
    n->left = NULL;
    n->right = NULL;
    return n;
}

/* Libera l’albero */
void free_tree(CharTree t)
{
    if (t == NULL) return;
    free_tree(t->left);
    free_tree(t->right);
    free(t);
}

/**
 * Implementare una funzione che calcola il numero di foglie presenti nell'albero:
 * 
 * @brief Dato un albero binario restituisce:
 * il numero di foglie (se l’albero è vuoto restituisce 0).
 */
int nfoglie(CharTree tree)
{
    if (tree == NULL) return 0;
    if (tree->left == NULL && tree->right == NULL) return 1;
    return (nfoglie(tree->left) + nfoglie(tree->right));
}

int main(void)
{
    /*
         A
        / \
       B   C
          / \
         D   E

    Foglie: B, D, E → 3
    */

    CharTree root = new_node('A');
    root->left = new_node('B');
    root->right = new_node('C');
    root->right->left = new_node('D');
    root->right->right = new_node('E');

    printf("Numero di foglie: %d\n", nfoglie(root));

    free_tree(root);
    return 0;
}