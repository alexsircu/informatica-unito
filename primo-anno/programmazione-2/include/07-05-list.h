typedef struct ln listnode, *listnodeptr;
struct ln {
    long val;
    listnodeptr next;
};

typedef struct l list, *listptr;
struct l {
    listnodeptr head;
};

listnodeptr createlistnode(long val);

listptr createlist();

void insertL(listptr l, long val);

int test_list();
