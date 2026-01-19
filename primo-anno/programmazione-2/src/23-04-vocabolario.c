#include "23-04-vocabolario.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

manyptr creamany(char val) {
    manyptr ret = malloc(sizeof(many));
    if (ret != NULL){
        ret->val = val;
        ret->figli = NULL;
    }
    return ret;
}

int addword(manyptr p, char* word){
    if (p->figli == NULL){
        p->figli = malloc(sizeof(manyptr) * 26);
        if (p->figli == NULL){
            return -1;
        }
        for (int i=0; i< 26; i++){
            p->figli[i] = NULL;
        }
    }
    manyptr *child = &(p->figli[*word-'a']);
    if (*child != NULL){
        if (*(word+1) == '\0'){
            return 0;
        }
         } else {
        *child = creamany(*word);
         if (*(word+1) == '\0'){
            return 1;
        }
         }
    return addword(*child,word+1);
}

int searchword(manyptr p, char* word){
    return 0;
}

char buf[1024*1024];
int pos = 0;

void stampaListaRic(manyptr p)
{
    pos += sprintf(buf + pos,"%c ",p->val);
    if (p->figli != NULL){
        pos += sprintf(buf + pos, "[ ");
    for(int i =0; i < 26; i++){
        manyptr pt = p->figli[i];
        if (pt != NULL){
            stampaListaRic(pt);
        }
        }
        pos += sprintf(buf + pos, "] ");
    }
}

char* tostring(manyptr p){
    pos =0;
    stampaListaRic(p);
    buf[pos] = '\0';
    return buf;
}

int test_creamany()
{
    int failures = 0;
    manyptr v = creamany('a');
    if (v != NULL) {
        if ( v->val != 'a' || v->figli != NULL) {
            failures += 1;
            fprintf(stderr, "err in creamany: %c %p\n",v->val,v->figli);
        }
    }
    return failures;
}

int test_searchword()
{
    int failures = 0;
    return failures;
}

int test_addword()
{
    int failures = 0;
    int retval =0;
    manyptr v = creamany(' ');
    retval = addword(v, "abc");
    if (retval != 1) {
         failures += 1;
         fprintf(stderr, "err in addword: %s \n","a");
    }
    fprintf(stderr, " '%s' \n",tostring(v));
    return failures;
}

int test_tostring()
{
    int failures = 0;
    return failures;
}

int test_vocabolario()
{
    int failures = 0;
    failures += test_creamany();
    failures += test_searchword();
    failures += test_addword();
    failures += test_tostring();
    return failures;
}
