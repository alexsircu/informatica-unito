#ifndef LIST_H
#define LIST_H

typedef struct Node* list; 
struct Node {
    int value;
    list next;
};

list remove_head(list l);
void delete_list(list* l);
list delete_list2(list l);
void delete_list3(list l);
void ins_ord(list* l, list node);
list ins_ord2(list l, list node);
#endif
