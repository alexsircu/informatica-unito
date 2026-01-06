#include "09-04-lista.h"
#include <stdio.h>

int main(void) 
{
  // c'erano int argc, char *argv[]
  printf("start testing\n");
  int ret = test_list();
  printf("Failures = %d\n", ret);
  return ret;
}
