#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <time.h>

void find_max_sequential(void);
void find_max_binary_search(void);
bool check_overflow(int curr);

int main(void) 
{
    find_max_sequential();
    find_max_binary_search();
}

void find_max_sequential(void)
{
    int curr = 1;
    bool overflow = false;

    while (!overflow) 
    {
        if (check_overflow(curr)) 
            overflow = true;
        else
            curr++;
    }

    printf("Using sequential search: \n");
    printf("The largest integer whose square does not overflow is: %d\n", curr - 1);
}

void find_max_binary_search(void)
{
    int low = 0;
    int high = INT_MAX;
    int result = 0;

    while (low <= high) 
    {
        int mid = low + (high - low) / 2;

        if (check_overflow(mid))
        {
            high = mid - 1;
        } else
        {
            result = mid;
            low = mid + 1;    
        }
    }

    printf("Using binary search: \n");
    printf("The largest integer whose square does not overflow is: %d\n", result);
}

bool check_overflow(int curr) 
{
    if (curr > 0 && curr > INT_MAX / curr) 
        return true;
    
    return false;
}
