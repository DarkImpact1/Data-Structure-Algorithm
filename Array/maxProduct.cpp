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
int maxProduct(vector<int>& nums) {
        long maxproduct = 0;
        int n = nums.size();
        for(int i=0; i< n; i++){
            int pr = nums[i];
            for(int j = i+1; j<n; j++){
                pr *= nums[j];
                if(maxproduct < pr){
                    maxproduct = pr;
                }else break;
            }
        }
        return maxproduct;
}

int main(){
    vector<int> vec = {-2,0,-1};
    cout<<brute_maxProduct(vec);
        
}