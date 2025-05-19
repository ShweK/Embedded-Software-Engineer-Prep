#include <iostream>
#include <climits>
using namespace std;
/*two pointer method*/
void PairSum(int *arr, int n, int target, int *ans){

        int start =0;
        int end = n-1;

        while(start <end)
        {
            int sum = arr[start] + arr[end];
            if(sum == target){
                ans[0] = arr[start];
                ans[1] = arr[end];
                return ; 
            }
            else if ( sum > target)
            {
                end = end -1;
            }
            else{
                start++;
            }
        }
}

int main(){

    int arr[] = {2,7,11,15};
    int n = 4; 
    int target = 9;
    int ans[2]={0};

    PairSum(arr,n,target, ans);
    cout<<"," << ans[0];
    cout<<", "<< ans[1];
}