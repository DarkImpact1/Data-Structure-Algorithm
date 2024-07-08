#include<bits/stdc++.h>
using namespace std;

int brute_reversePairs(vector<int>& nums) {
    int pair = 0;
    int n = nums.size();
    for(int i=0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(nums[i] > (2 * nums[j])){
                pair++;
            }
        }
    }
    return pair;
}

int main() {
   vector<int> vec = {2,4,3,5,1};
    cout<<brute_reversePairs(vec)<<endl;

    return 0;
}