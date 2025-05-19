#include <iostream>
using namespace std;

/*Step1 : use linear search */
bool FindKeyBF(int mat[][4], int m, int n , int key){     // note compiler asks for colums number for syntax of 2D matrix

    for(int i =0; i < m ; i++){

        for(int j =0; j < n ; j++)
        {
            if(mat[i][j] == key)
            {
                return true;
            }
        }
    }

    return false;


}


int main(){
    int mat[4][4] = {{10,20,30,40},
                         {15,25,35,45},
                         {27,29,37,48},
                         {32,33,39,50}};
        int key = 45;
        int n = 4;
        int m =4;
        cout << FindKeyBF(mat,m,n,key)<< endl;

}