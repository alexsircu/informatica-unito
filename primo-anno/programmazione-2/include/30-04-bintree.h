typedef struct n binnode, *binnodeptr;
struct n {
    long val;
    binnodeptr left;
    binnodeptr right;
};

typedef struct b bintree, *bintreeptr;
struct b {
    binnodeptr root;
};

int test_bintree();