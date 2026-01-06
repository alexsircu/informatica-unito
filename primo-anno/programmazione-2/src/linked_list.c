#include <stdlib.h>
/*#include "linked_list.h"

// =================================================================
//                        remove head list
// =================================================================
list remove_head(list l)
{
    if (!l) return NULL;

    list tmp = l;
    l = l->next;
    free(tmp);
    return l; 
}

// =================================================================
//          recursive list deleting - pass by reference
// =================================================================

// Passing &(*l)->next allows the function to update each pointer to NULL
// after freeing the node. The last node triggers the recursive call but
// skips the inner if, ensuring proper cleanup.

void delete_list(list* l)
{
    if (l)
    {
        if (*l)
        {
            delete_list(&(*l)->next);
            free(*l);
            *l = NULL;
        }
    }
}

// =================================================================
//              recursive list deleting - pass by value
// =================================================================

// The assignment l->next = delete_list2(l->next) is not actually needed,
// since the function always returns NULL; it simply follows the common
// recursive pattern before freeing the current node.

list delete_list2(list l)
{
    if (l)
    {
        l->next = delete_list_2(l->next);
        free(l);
        return NULL;
    }
    else
    {
        return NULL;
    }
}

// =================================================================
//                     iterative list deleting
// =================================================================
void delete_list3(list l)
{
    while (l)
    {
        list tmp = l;
        l = l->next;
        free(tmp);
    }
}

// =================================================================
//   recursive node inserting in ordered list - pass by reference
// =================================================================
void ins_ord(list* l, list node)
{
    if (l)
    {
        if (*l)
        // if the list is not empty 
        {
            if (node->value <= (*l)->value)
            {
                // to add in first position
                node->next = *l;
                *l = node;
            }
            else if (!(*l)->next) 
            {
                // to add in last position
                // already know that node->value > l->value from previous "if"  
                (*l)->next = node;
                node->next = NULL;
            }
            else if (node->value < (*l)->next->value) 
            {
                // to add in a middle position
                // node->value > l->value is already guaranteed
                node->next = (*l)->next;
                (*l)->next = node;
            }
            else
            {
                // position not yet reached, recursive step
                ins_ord(&(*l)->next, node);
            }
        }
    }
    else
    {
        return node;
    }
}

// =================================================================
//     recursive node inserting in ordered list - pass by value
// =================================================================
list ins_ord2(list l, list node)
{
    if (l)
    {
        if (node->value <= l->value)
        {
            // to add in first position
            node->next = l;
            return node;
        }
        else if (!l->next) 
        {
            // to add in last position
            // already know that node->value > l->value from previous "if"  
            l->next = node;
            node->next = NULL;
            return l;
        }
        else if (node->value < l->next->value) 
        {
            // to add in a middle position
            // node->value > l->value is already guaranteed
            node->next = l->next;
            l->next = node;
            return l;
        }
        else
        {
            // position not yet reached, recursive step
            l->next = ins_ord2(l->next, node);
            return l;
        }
    }
    else
    {
        return node;
    }
}

*/
