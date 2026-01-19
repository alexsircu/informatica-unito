#include "23-04-vocabolario.h"

#include <stdio.h>

int main(int argc, char* argv[])
{
    printf("start testing\n");
    int ret = test_vocabolario();
    printf("Failures = %d\n", ret);
    return ret;
}
