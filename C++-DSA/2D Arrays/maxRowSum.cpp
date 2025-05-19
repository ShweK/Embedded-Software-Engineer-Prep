#include <iostream>
#include <climits>

using namespace std;
int maxSum = INT_MIN;       // note - climits needs to be included
/*Step1 : use linear search */
int maxRowSumBF(int mat[][4], int m, int n){     // note compiler asks for colums number for syntax of 2D matrix

    for(int i =0; i < m ; i++){
        int rowSum =0;
        for(int j =0; j < n ; j++)
        {
            rowSum +=mat[i][j];  
        }
        maxSum = max(maxSum, rowSum);
    }

    return maxSum;


}


int main(){
    int mat[4][4] = {{1,2,3,4},
                         {5,6,7,8},
                         {9,10,11,12},
                         {10,10,15,15}};

        int n = 4;
        int m =4;
        cout << maxRowSumBF(mat,m,n)<< endl;

}