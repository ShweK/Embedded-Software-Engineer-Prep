#include <iostream>
using namespace std;

int linearSearch(int *arr, int n, int t)
{
    //simple for loop, TC : O(n)
    for(int i = 0; i<n; i++)
    {
        if(arr[i]==t)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {4,2,7,8,1,2,5};
    int size = sizeof(arr)/sizeof(int);
    int target =8;

    cout <<"Target found at " <<linearSearch(arr,size,target)<<endl;
}