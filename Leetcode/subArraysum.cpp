#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums){
    int m = 1e9+7;
    int sum = 0;
    int n = nums.size();
    for(int i=0; i<n;i++){
        int left_contri = ((nums[i]%m)*((i+1)%m))%m;
        int whole_contri = ((left_contri%m)*((n-i)%m))%m;
        sum += whole_contri;
    }
    return sum;
}

int subMatrixSum(vector<vector<int>> &matrix){
    int row = matrix.size();
    int col = matrix[0].size();
    int sum = 0;
    for(int r=0; r<row; r++){
        for(int c=0; c<col; c++){
            sum += matrix[r][c]*(r+1)*(c+1)*(n-r)*(n-c);
        }
    }
    
}
int main() {
    vector<int> nums = {1,2,3};
    
    
    cout<<subarraySum(nums);
}
