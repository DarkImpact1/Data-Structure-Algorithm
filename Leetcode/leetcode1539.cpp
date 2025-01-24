/*
1539. Kth Missing Positive Number
Solved
Easy
Topics
Companies
Hint
Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Return the kth positive integer that is missing from this array.
*/




#include <bits/stdc++.h>
using namespace std;

// brute force method to find the answer
int kthMissing(vector<int>&nums,int k){
    for(auto it: nums){
        if(it<= k){
            k++;
        }
        else break;
    }
    return k;
}
// optimised way to find the answer;

int missingTill(vector<int> &nums, int ideal){
    return nums[ideal]-(ideal+1);
}
// int moreNumReq(int )
int findKthPositive(vector<int>& nums, int k){
    int low = 0, high = nums.size()-1;
    while(low<= high){
        int mid = (low+high)/2;
        int cnt_missing = missingTill(nums, mid);
        if(cnt_missing < k){
            low = mid+1;
        }else{
            if(mid == 0) {
                high = 0;
                break;
            }
            else high = mid-1;
        }
    }
    /*
    answer will be arr[high]+ k-missing
    missing = arr[high] - high -1;
    answer = arr[high] + k - (arr[high] -high -1)
    arr[high]+ k -arr[high] + high +1;
    answer = high +1 + k;
    also remebver low will be at high+1;
    therefor answer can be low+1  as well
    
    */
    return high+1+k;
}
int main() {
    vector<int> arr = {2,3,4,7,11};
    cout << findKthPositive(arr,3);
    
    return 0;
}
