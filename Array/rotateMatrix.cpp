#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> brute_RotateMatrix(vector<vector<int>> matrix){
    int nR =matrix.size();
    vector<vector<int>> Rmatrix(nR, vector<int>(nR));
    for(int i=0; i<nR; i++){
        for(int j=0; j<nR; j++){
            Rmatrix[i][j] = matrix[nR-j-1][i];
        }
    }
    return Rmatrix;
}


int main(){
    vector<vector<int>> matrix ={
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    vector<vector<int>> mat = RotateMatrix(matrix);
    for(auto row : mat){
        for(auto ele : row){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}