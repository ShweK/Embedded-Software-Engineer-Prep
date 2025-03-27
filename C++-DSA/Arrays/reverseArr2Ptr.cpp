#include <iostream>
using namespace std;

void reverseArr(int *arr, int n)
{
  //using 2 pointer approach
  int start=0;
  int end = n-1;

  while(start < end)
  {
    swap(arr[start],arr[end]);
    start++;
    end--;
  }

  //print arr
  cout <<"Reversed arr: ";
  for(int i= 0 ; i<n; i++)
  {
    cout<< arr[i] <<",";
  }
  cout<<endl;
}


int main()
{
   int arr[] = {4,2,7,8,1,2,5};
   int n = sizeof(arr)/sizeof(int);
   //print original array
   cout<<"Original arr: ";
   for(int i = 0; i< n; i++)
   {
    cout << arr[i] << ",";
   }
   cout <<endl;
   reverseArr(arr,n);
}