#include <iostream>
#include <climits>

using namespace std;
/*concept : it is diag sum is calculated on m==n matrix which is a square matrix
there is PD(primary Diagonal) where i ==j*/
/*SD (secondary diagnal) where j = n-1-i*/
/*Step1 : traverse through the matrix */
int diagSum(int mat[][4], int n){     // note compiler asks for colums number for syntax of 2D matrix
// use singl;e loop as 
//PD j ==i 
//SD j = n-1-i
int sum =0;
    for(int i =0; i < n ; i++){
        sum +=mat[i][i]; //PD
        if(i != n-1-i){
            sum+= mat[i][n-1-i]; //SD
        }
    }

    return sum;


}


int main(){
    int mat[4][4] = {{1,2,3,4},
                         {5,6,7,8},
                         {9,10,11,12},
                         {10,10,15,15}};

        int n = 4;
        cout << diagSum(mat,n)<< endl;

}