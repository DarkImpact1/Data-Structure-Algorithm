#include<bits/stdc++.h>
using namespace std;


vector<int> printSpiral(vector<vector<int>>& matrix){
    int left = 0, top = 0;
    int right = matrix[0].size() - 1, bottom = matrix.size() - 1;
    vector<int> ans;

    while (top <= bottom && left <= right) {
        for (int k = left; k <= right; k++) {
            ans.push_back(matrix[top][k]);
        }
        top += 1;

        for (int k = top; k <= bottom; k++) {
            ans.push_back(matrix[k][right]);
        }
        right -= 1;

        if (top <= bottom) {
            for (int k = right; k >= left; k--) {
                ans.push_back(matrix[bottom][k]);
            }
            bottom -= 1;
        }

        if (left <= right) {
            for (int k = bottom; k >= top; k--) {
                ans.push_back(matrix[k][left]);
            }
            left += 1;
        }
    }
    return ans;
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