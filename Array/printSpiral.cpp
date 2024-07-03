#include<bits/stdc++.h>
using namespace std;


vector<int> printSpiral(vector<vector<int>>& matrix){
    int nR = matrix.size();
    int nC = matrix[0].size();
    for(int i = 0; i<nR; i++){
        
    }
}

int main(){
    vector<vector<int>> matrix ={
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    for(auto ele : printSpiral(matrix)){
        cout<<ele<<" ";
    }
    cout<<endl;
}