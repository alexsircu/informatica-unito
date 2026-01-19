#ifndef VOCABOLARIO_H
#define VOCABOLARIO_H

typedef struct n many, *manyptr;

struct n {
    manyptr* figli;
    char val;
    //    char isword;  // trascurare per ora
};

manyptr creamany(char val);
int addword(manyptr p, char* word);
int searchword(manyptr p, char* word);
char* tostring(manyptr p);

int test_creamany();
int test_searchword();
int test_addword();
int test_tostring();
int test_vocabolario();

#endif
