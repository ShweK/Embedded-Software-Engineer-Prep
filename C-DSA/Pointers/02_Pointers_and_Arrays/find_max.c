#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

int findMax(const int *arr, int size)
{

    if(size <= 0 || arr == NULL)
    {
        return -1;
    }
    const int *ptr = arr;
    const int *end_ptr = arr + size;
    int largest = *ptr;

    while(ptr< end_ptr)
    {
        if(*ptr > largest)
        {
            largest = *ptr;
        }
        ptr++;
    }
    return largest;
}

int main()
{
    int arr[5] = {12, 5, 28, 9, 17};
    int result = findMax(arr, 5);
    printf("largest is %d \n", result);
    return 0;
}