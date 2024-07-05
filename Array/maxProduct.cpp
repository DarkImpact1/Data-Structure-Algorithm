#include <bits/stdc++.h>
using namespace std;
int brute_maxProduct(vector<int>& nums){
    int mp = INT_MIN;
    int n = nums.size();
    for(int i =0; i<n; i++){
        for(int j = i; j<n; j++){
            int p = 1;
            for(int k = i; k<=j; k++){
                p *= nums[k];
            }
            mp = max(mp,p);
        }
    }
    return mp;
}


int better_maxProduct(vector<int>& nums){
    int mp = INT_MIN;
    int n = nums.size();
    for(int i =0; i<n; i++){
        int p = 1;
        for(int j = i; j<n; j++){
                p *= nums[j];
                mp = max(mp,p);
        }
        
    }
    return mp;
}
    int maxProduct(vector<int>& nums) {
        int mxp = INT_MIN;  // Maximum product initialized to the smallest integer
        int n = nums.size();
        long long pre = 1, suf = 1;
        for(int i = 0; i < n; i++) {
            if(pre == 0) pre = 1;
            if(suf == 0) suf = 1;
            pre *= nums[i];
            suf *= nums[n - i - 1];
            // Reset pre and suf if they exceed 32-bit integer bounds
            if(pre > INT_MAX || pre < INT_MIN) pre = nums[i];
            if(suf > INT_MAX || suf < INT_MIN) suf = nums[n - i - 1];
            mxp = max(mxp, max((int)pre, (int)suf));
        }
        return mxp;
    }

int main(){
    vector<int> vec = {0,2};
    cout<<better_maxProduct(vec);
        
}