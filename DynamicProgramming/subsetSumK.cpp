#include <bits/stdc++.h>
using namespace std;

// let's go with the recursion first
bool subSetSumK(vector<int>& nums, int k, int n){
    if(k == 0){
        return true;// basically we found the sum
    }
    if(n == 0 && k != 0){ // we don't have element and didn't foudn sum
        return false;
    }
    if(nums[n-1] <= k){
        bool inc = subSetSumK(nums, k-nums[n-1], n-1);
        bool n_inc = subSetSumK(nums, k, n-1);
        return inc || n_inc;  
    }
    
    return subSetSumK(nums, k, n-1);
}

bool topDown(vector<int>& nums, int k, int n){
    vector<vector<bool>> t(n+1,vector<bool>(k+1));

  // Initialisation is very important so take care of it other wise it is same as knapsack
    int r = 0;
    while(r < n+1){
        t[r][0] = true;
        r++;
    }
    int c = 1;
    while(c < k+1){
        t[0][c] = false;
        c++;
    }
    for(int i = 1; i < n+1; i++){
        for(int j = 1; j< k+1; j++){
            if(nums[i-1] <= j){
                bool inc = t[i-1][j-nums[i-1]];// include the el
                bool n_inc = t[i-1][j]; // not inc ele
                t[i][j] = inc || n_inc;
            }else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    
    return t[n][k];
}

int main() {
    vector<int> arr = {2, 3, 7,8,10};
    int n = arr.size();
    int sum = 6;

    bool found = topDown(arr, sum, n);
    cout << "is present " << found << endl;

    return 0;
}
