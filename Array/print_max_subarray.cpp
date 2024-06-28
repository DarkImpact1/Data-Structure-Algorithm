#include<bits/stc++.h>
using namespace std;

// Kadane's algorithm for max_subarray O(n) returning vector
vector<int> Max_subarray(vector<int> nums){
    int m=INT_MIN;
    int startIndex = -1;
    int endIndex = -1;
    int start = 0;
    int s=0;
    for(int i=0; i<nums.size(); i++){
        if(s == 0){
        start = i;
            
        }
        s += nums[i];
        if(s > m){
            m = s;
            startIndex = start;
            endIndex = i;
        }
        if(s < 0) s = 0;
    }
    vector<int> ans;
    for(int i=startIndex; i<=endIndex;i++){
        ans.push_back(nums[i]);
    }
    return ans;
}
int main() {
    vector<int> vec = {5,4,-1,7,8};
    vector<int> ans = Max_subarray(vec);
    for(int i: ans){
        cout<<i<<" ";
    }

    return 0;
}