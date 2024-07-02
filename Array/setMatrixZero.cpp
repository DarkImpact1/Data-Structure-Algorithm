#include<bits/stdc++.h>
using namespace std;


// funtion inside brute_setZero
void setRow(int row, vector<vector<int>>& matrix){
    int nC = matrix[0].size();
    for(int col=0; col<nC; col++){
        if(matrix[row][col] != 0){
            matrix[row][col] = -1;
        }
    }
}
// funtion inside brute_setZero
void setCol(int col, vector<vector<int>>& matrix){
    int nR = matrix.size();
    for(int row=0; row<nR; row++){
        if(matrix[row][col] != 0){
            matrix[row][col] = -1;
        }
    }
    
}
void brute_setZero(vector<vector<int>>& matrix){
    int nR = matrix.size();
    int nC = matrix[0].size();
    for(int row = 0; row < nR; row++){
        for(int col = 0; col < nC; col++){
            if(matrix[row][col] == 0){
                setRow(row, matrix);// converting all the vales to -1
                setCol(col,matrix);// converting all the values to -1
            }
        }
    }
    
    // now converting -1 to zero
    
    for(int row=0; row <nR; row++){
        for(int col=0; col<nC; col++){
            if(matrix[row][col] == -1){
                matrix[row][col]=0;
            }
        }
    }
    //end
}



int main(){
 vector<vector<int>> vec = {
        {1, 1, 1, 1},
        {1, 0, 0, 1},
        {1, 1, 1, 1}
    };
    brute_setZero(vec);
    for(auto row : vec){
        for(auto ele : row){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}