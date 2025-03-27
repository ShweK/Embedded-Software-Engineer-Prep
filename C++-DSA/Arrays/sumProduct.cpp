#include <iostream>
using namespace std;

int sum(int *arr, int n)
{
    int sum = 0;
    for(int i =0; i<n; i++)
    {
        sum+=arr[i];
    }
    return sum;
}

int product(int *arr, int n)
{
    int product = 1;
    for(int i =0; i<n; i++)
    {
        product*=arr[i];
    }
    return product;
}
int main()
{
    int arr[] = {1,2,3,4};
    int size = sizeof(arr)/sizeof(int);
    cout <<"Sum of array: " <<sum(arr,size)<<endl;
    cout <<"Product of array: " <<product(arr,size)<<endl;

}