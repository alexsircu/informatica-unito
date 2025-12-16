#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define ARR_LENGTH 11

void get_inverse_input_static_array(void);
void get_inverse_input_dynamic_array(void);

int main(void)
{
    get_inverse_input_static_array();
    get_inverse_input_dynamic_array();
}

void get_inverse_input_static_array(void)
{
    char arr[ARR_LENGTH];
    char tmp[ARR_LENGTH];

    printf("STATIC ARRAY\n");
    printf("Insert a string composed by max %d characters\n", ARR_LENGTH - 1);
    
    scanf("%s", tmp);
    int len = strlen(tmp);
    int j = 0;

    for (int i = len - 1; i >= 0; i--)
    {
        arr[j] = tmp[i];
        j++; 
    }

    arr[j] = '\0';    
    printf("%s\n", arr);
}

void get_inverse_input_dynamic_array(void)
{
    char* arr;
    char tmp[ARR_LENGTH];

    printf("DYNAMIC ARRAY\n");
    printf("Insert a string composed by max %d characters\n", ARR_LENGTH - 1);

    scanf("%s", tmp);
    int len = strlen(tmp);

    arr = (char*) malloc(sizeof(char) * (len + 1));
    int j = 0;

    for (int i = len - 1; i >= 0; i--)
    {
        arr[j] = tmp[i];
        j++; 
    }

    arr[j] = '\0';    
    printf("%s\n", arr);
}
