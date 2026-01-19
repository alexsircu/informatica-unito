#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum tt {num,ptr, cstar};
typedef enum tt tipo;

typedef struct u esempio,*esempioptr;
struct u
{
    tipo type;
    union
    {
        long number;
        void *punt;
        char big[10000];
    };
};


typedef struct v esempiov;
struct v
{
    tipo type;
    void * cont;
};

long v =10;
void come_un(void) 
{
    esempio e = {num,{8}};
    if (e.type == num){
        printf("%ld\n",e.number);
    } else {
         printf("%p\n",e.punt);
    }
    e.type = ptr;
    e.punt = (void*) & v;
    if (e.type == num){
        printf("%ld\n",e.number);
    } else {
         printf("%p\n",e.punt);
         printf("deref: %ld\n",*(long*)(e.punt));
    }
}

void come_void(void)
{
    esempiov e = {num,(void*)8};
    if (e.type == num){
        printf("%ld\n",(long) e.cont);
    } else {
         printf("%p\n",e.cont);
    }
    e.type = ptr;
    e.cont = (void*) & v;
    if (e.type == num){
        printf("%ld\n",(long) e.cont);
    } else {
         printf("%p\n",e.cont);
    }
}

char * valori[] = {"num","ptr", "cstar"};
char*  formati[] = {"{%s %ld}","{%s %p}","{%s %s}"};

int tostr(char *tmpstr, esempioptr miaunion){
   int stampati =0;
   if (miaunion == NULL){
       stampati = sprintf(tmpstr,"NULL");
   } else {
       stampati = sprintf(tmpstr,formati[miaunion->type],valori[miaunion->type],miaunion->punt);
   }
   // codice
   tmpstr[stampati] = '\0';
   return stampati;
}


int fromstr(esempioptr miaunion,char *tmpstr){
   int retval =0;
   if (miaunion == NULL || tmpstr== NULL || *tmpstr =='\0'){
       return 0;
   } 
   char buftipo[10],bufvalore[12000];
   sscanf(tmpstr,"{%s %s}",buftipo,bufvalore);
   if (bufvalore[strlen(bufvalore)-1] == '}'){
       bufvalore[strlen(bufvalore)-1]= '\0';
	}
   printf("trovati '%s' '%s'\n",buftipo,bufvalore);

   size_t i = 0;
   for (; i < sizeof(valori)/sizeof(valori[0]);i++){
    if (strcmp(valori[i],buftipo) == 0){
        break;
    }
   }
   miaunion->type = i;
   if (i==0) miaunion->number = atoi(bufvalore);
   //(tmpstr,formati[miaunion->type],valori[miaunion->type],miaunion->punt);
  
   return retval;
}

char tmpstring[20000];

void test_un(void)
{
    esempio miaunion = {num,{8}};
    tostr(tmpstring,&miaunion);
    printf("la union e': '%s'\n",tmpstring);
    fromstr(&miaunion,tmpstring);
   // come_un();
  //  come_void();
}
