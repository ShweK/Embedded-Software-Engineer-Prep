#include <iostream>
#include <climits>
using namespace std;

void swapMinMax(int *arr, int n)
{
    int min_value = INT_MAX;
    int max_value = INT_MIN;
    int min_index, max_index =0;

    for(int i = 0; i <n; i++)
    {
        min_value = min(min_value,arr[i]);
        if(min_value == arr[i])
        {
            min_index =i;
        }
        max_value = max(max_value,arr[i]);
        if(max_value == arr[i])
        {
            max_index =i;
        }
    }
    arr[min_index]= max_value;
    arr[max_index]= min_value;
   //print the arr
   for(int i= 0 ; i<n; i++)
   {
     cout<< arr[i] <<",";
   }
}

int main()
{

    int arr[] = {2,4,9,3,1};
    int n= sizeof(arr)/sizeof(int);
    swapMinMax(arr,n);
    return 0;
}