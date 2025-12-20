#include <stdio.h>

int main(void)
{
    struct test
    {
        char x;
        char y;
        int z;
    };

    int size = (sizeof(char) * 2) + (sizeof(int)); // 6 byte?
    printf("The size of size is: %d\n", size);
    printf("The size of strcut is: %ld\n", sizeof(struct test));
}
