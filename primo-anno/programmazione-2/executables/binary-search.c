#include <stdio.h>

#define ARR_SIZE 10

int binary_search(char el, char array[], int sx, int dx);

int main(void)
{
    char arr[ARR_SIZE] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'L'};
    int result = binary_search('A', arr, 0, ARR_SIZE - 1);

    if (result != -1)
        printf("Found at position: %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}

int binary_search(char el, char array[], int sx, int dx)
{
    int ret = 0;

    if (sx > dx)
        ret = -1;

    int middle = (dx + sx) / 2;

    if (el == array[middle])
        ret = middle;
    else if (el < array[middle])
        ret = binary_search(el, array, sx, middle - 1);
    else if (array[middle] < el)
        ret = binary_search(el, array, middle + 1, dx);

    return ret;
}
