#include <stdio.h>
#include "30-04-bintree.h"

typedef void * jolly;   // per leggibilita’
void prove(){
   long a = 97;
    jolly c = &a;
    char * p = c;
    printf("%s\n",c); // W da pointer a formato specifico
    printf("%s\n",p);
    jolly b = (jolly)a;
    char d = b;  //W size diversa
    char e = (char) b; //W size diversa
    long f = b; // W da pointer a tipo, anche se stessa size
    long ll = (long) b; // OK stessa size
    char g = (char) f; // OK
    printf("%c %c %c %c\n",d,e,f,g); 
}

int main(int argc, char** argv)
{
    int ret = 0;
    ret += test_bintree();
    printf("Failures = %d\n", ret);
    return ret;
}
