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

// in this approach we'll keep the track of col & row where the value is zero. then re iterate and mark them 0 in original array which will reduce our time complexity
void better_setZero(vector<vector<int>>& matrix){
    int nR = matrix.size();
    int nC = matrix[0].size();
    int row[nR]={0}; 
    int col[nC]={0};
    
    for(int i=0; i<nR; i++){
        for(int j=0; j<nC; j++){
            if(matrix[i][j]==0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
// re iterating and marking then as zero
    for(int i=0; i<nR; i++){
        for(int j=0; j<nC; j++){
            if(row[i] || col[j]){
                matrix[i][j]=0;
            }
        }
    }
}

int main(){
 vector<vector<int>> vec = {
        {1, 1, 1, 1},
        {1, 0, 0, 1},
        {1, 1, 1, 1}
    };
    // brute_setZero(vec)// around O(n**3)
    better_setZero(vec); // O(n**2)
    for(auto row : vec){
        for(auto ele : row){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}