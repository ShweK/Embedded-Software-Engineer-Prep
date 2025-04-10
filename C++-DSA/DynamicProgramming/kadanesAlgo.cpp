#include <iostream>
#include <climits>
using namespace std;

void kadanesAlgo(int *arr, int n)
{
    int currSum =0;
    int maxSum = INT_MIN;

    for(int st =0; st <n ; st++)
    { 
        currSum += arr[st];
        maxSum = max(currSum, maxSum);
        
        if(currSum < 0)
        {
            currSum = 0;
        }

    }
    cout << "maxsum " <<maxSum << endl;

}


int main()
{
    int arr[] = {3,-4,5,4,-1,7,-8};
    int n = sizeof(arr)/sizeof(int);

    kadanesAlgo(arr, n);
}