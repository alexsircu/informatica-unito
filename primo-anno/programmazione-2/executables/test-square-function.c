# include <stdio.h>

int square(int num) 
{
    int ret = 0;

    if (num < 0) 
        num = -num;

    for (int i = 0; i < num; i++)
        ret += num;
    
    return ret;
}

int power(int num, int exp)
{
    int ret = 1;

    if (exp < 0)
        return -1;

    if (exp == 0)
        return 1;

    for (int i = 0; i < exp; i++)
        ret *= num;

    return ret;
}

void test_square(int nums[], int expected_results[], int size) 
{
    for (int i = 0; i < size; i++)
    {
        printf("Testing square function: the number is %d and the result should be %d\n", nums[i], expected_results[i]);
        int result = square(nums[i]);

        if (!result)
            printf("Negative exp not implemented.\n");

        if (result != expected_results[i]) 
            printf("Test failed: expected %d but got %d\n", expected_results[i], result);
        else 
            printf("Test passed: got expected result %d\n", result);
    }
}

void test_power(int nums[], int exps[], int expected_results[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Testing power function: the number is %d raised to %d and the result should be %d\n", nums[i], exps[i], expected_results[i]);
        int result = power(nums[i], exps[i]);

        if (result != expected_results[i]) 
            printf("Test failed: expected %d but got %d\n", expected_results[i], result);
        else 
            printf("Test passed: got expected result %d\n", result);
    }
}

int main(void) 
{
    int square_nums[] = {0, 1, 2, 3, 4, 5, -4, -2};
    int square_expected_results[] = {0, 1, 4, 9, 16, 25, 16, 4};
    int square_num_tests = sizeof(square_nums) / sizeof(square_nums[0]);

    test_square(square_nums, square_expected_results, square_num_tests);

    int power_nums[] = {0, 4, -7, 10, -2};
    int exps[] = {2, 3, 2, 1, 5};
    int power_expected_results[] = {0, 64, 49, 10, -32};
    int power_num_tests = sizeof(power_nums) / sizeof(power_nums[0]);

    test_power(power_nums, exps, power_expected_results, power_num_tests);
}
