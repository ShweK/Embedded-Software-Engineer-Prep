#include <iostream>
using namespace std;

void findIntersection(int *arr, int *arr2, int n)
{
    int result;

    for(int i= 0; i<n ; i++)
    {
        for(int j =0; j<n; j++)
        {
            if(arr[i]==arr2[j])
            {
                cout<< arr[i] <<endl;
            }
        }
    }

}

int main()
{
    int arr[] = {1,3,4,5};
    int arr2[]= {6,7,3,1};
    //assume both arrays as same size
    findIntersection(arr, arr2, 4);

}