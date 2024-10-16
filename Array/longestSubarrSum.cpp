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
        sum+=nums[right];
    }
    return maxlen-1;
}
/*
Problem max length of subarrya which can yield sum <= k
    */
int optimalLongestSubrrayK(vector<int> &arr, int k){
    int l = 0, r = 0, n = arr.size(), sum = 0, maxlen = 0;
    while(r < n){
        sum = sum + arr[r];
        while(sum > k && (r-l+1) > maxlen){
            sum = sum - arr[l];
            l = l+1;
        }
        if(sum <= k){
            maxlen = max(maxlen,r-l+1);
        }
        r = r+1;
    }
    return maxlen;
}

int main() {
    string name = "babad";
    vector<int> arr = {12,8,1,7,10};
    int length = optimalLongestSubrrayK(arr, 11);
    cout<<"Max lenght of subarray with sum <= "<<k<<" : "<<length<<endl;
    
    vector<int> vec  = {0,1,1,1,1,1,1};
    int k = 6;
    cout<<"Max lenght of subarray with sum "<<k<<" : "<<maxSubarraySum(vec,k);
    

    return 0;
}
