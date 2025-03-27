#include <iostream>
#include <climits>
using namespace std;
void findMinMax(int *arr, int n)
{
  int min = INT_MAX;
  int max = INT_MIN;
  int min_index=0;
  int max_index=0;

  for(int i =0; i<n; i++)
  {
    if(arr[i]<min)
    {
        min = arr[i];
    }
    if(arr[i]==min)
    {
        min_index = i;
    }
    if(arr[i]>max)
    {
        max = arr[i];
    }
    if(arr[i]==max)
    {
        max_index =i;
    }
  }
  cout <<" min at index "<<min_index<<" is " <<min<<endl;
  cout <<" max at index "<<max_index<<" is "<<max<<endl;
}
int main()
{
    int nums[] = {5,12,-11,6,24};
    int n = sizeof(nums)/sizeof(int);
    findMinMax(nums,n);
}