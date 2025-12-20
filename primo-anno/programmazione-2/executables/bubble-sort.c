#include <stdio.h>

#define ARRAY_SIZE 5

void bubble_sort(int arr[], int size);
void print_array(int arr[], int size);

int main(void)
{
    int arr[ARRAY_SIZE] = {5, 3, 8, 6, 2};

    printf("Array before sorting:\n");
    print_array(arr, ARRAY_SIZE);
    
    bubble_sort(arr, ARRAY_SIZE);

    printf("Array after sorting:\n");
    print_array(arr, ARRAY_SIZE);

    return 0;
}

void bubble_sort(int arr[], int size)
{
    int tmp = 0;
    int done = 0;

    while (!done) 
    {
        done = 1;

        for (int i = 1; i < size; i++)
        {
            if (arr[i - 1] > arr[i])
            {
                tmp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = tmp;
                done = 0;
            }
        }
    }
}

void print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
