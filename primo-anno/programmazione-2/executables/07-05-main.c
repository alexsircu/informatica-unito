#include <stdio.h>
#include "07-05-list.h"

void test_un(void);

int main(int argc, char** argv)
{
    int ret = 0;
    ret += test_list();
    printf("Failures = %d\n", ret);
    test_un();
    return ret;
}
