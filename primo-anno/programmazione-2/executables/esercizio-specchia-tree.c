#include <stdio.h>
#include <stdlib.h>

typedef struct intTreeNode IntTreeNode, *IntTree;
struct intTreeNode {
    IntTree left;
    int data;
    IntTree right;
};

/* =================== */
/* Funzioni ausiliarie */
/* =================== */

/* Crea un nuovo nodo */
IntTree new_node(int num)
{
    IntTree n = malloc(sizeof(IntTreeNode));
    if (!n) return NULL;
    n->data = num;
    n->left = NULL;
    n->right = NULL;
    return n;
}

/* Libera l’albero */
void free_tree(IntTree t)
{
    if (t == NULL) return;
    free_tree(t->left);
    free_tree(t->right);
    free(t);
}

/**
* @brief Trasforma un albero nella sua versione speculare.
*
* P-IN: tree è un albero binario valido (o NULL).
* P-OUT: l’albero originale viene modificato in-place scambiando
ricorsivamente i sottoalberi sinistro e destro di ogni nodo.
*/

void mirror(IntTree tree) 
{
    if (tree == NULL) return;

    IntTree tmp = tree->left;
    tree->left = tree->right;
    tree->right = tmp;

    mirror(tree->left);
    mirror(tree->right);
}

int main(void)
{
    /*
         3
        / \
       2   7
          / \
         6   8
    */

    IntTree root = new_node(3);
    root->left = new_node(2);
    root->right = new_node(7);
    root->right->left = new_node(6);
    root->right->right = new_node(8);

    //printf("Numero di foglie: %d\n", nfoglie(root));

    free_tree(root);
    return 0;
}