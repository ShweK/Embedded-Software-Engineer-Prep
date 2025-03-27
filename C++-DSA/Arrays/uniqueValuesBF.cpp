#include <iostream>
using namespace std;

void uniqueValues(int *arr, int n )
{  

    for(int i =0; i <n ; i++)
    {   
        bool isunique = true;
        for(int j =0; j < n; j++)
        {
            if(arr[i]== arr[j] && i!=j)
            {
                isunique = false;
                break;
            }
        }
        if(isunique)
        {
            cout<<arr[i] <<" is unique"<<endl;
        }
    }

}

int main()
{
    int arr[] = {1,2,3,1,5,3,4,2};
    int size = sizeof(arr)/sizeof(int);
    uniqueValues(arr, size);
}