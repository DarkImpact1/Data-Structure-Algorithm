#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> brute_RotateMatrix(vector<vector<int>>& matrix){
    int nR =matrix.size();
    vector<vector<int>> Rmatrix(nR, vector<int>(nR));
    for(int i=0; i<nR; i++){
        for(int j=0; j<nR; j++){
            Rmatrix[i][j] = matrix[nR-j-1][i];
        }
    }
    return Rmatrix;
}


// transpose the matrix and then reverse the row.. you'will get you answer
void optimal_RotateMatrix(vector<vector<int>>& matrix){
    int nR =matrix.size();
    for(int i=0; i<nR-1; i++){
        for(int j=i+1; j<nR; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (int i = 0; i < nR; ++i) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}


int main(){
    vector<vector<int>> matrix ={
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    // vector<vector<int>> mat = brute_RotateMatrix(matrix);
    optimal_RotateMatrix(matrix);
    for(auto row : matrix){
        for(auto ele : row){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}