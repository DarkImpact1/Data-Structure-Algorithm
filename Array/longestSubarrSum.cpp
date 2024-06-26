/*
Problem : find the longest subarray which can yeild the sum k
*/


#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum(vector<int> nums, int k){
    int left = 0,right = 0 , maxlen =0;
    int sum = nums[0];
    int n = nums.size();
    while(right < n){
        while(left <= right && sum > k){
            sum -= nums[left];
            left++;
        }
        if(sum == k){
            maxlen = max(maxlen, right - left + 1);
        }
        right++;
        if(right < n) sum+=nums[right];
    }
    return maxlen-1;
}

int main() {
    vector<int> vec  = {0,1,1,1,1,1,1};
    int k = 6;
    cout<<"Max lenght of subarray with sum "<<k<<" : "<<maxSubarraySum(vec,k);
    

    return 0;
}