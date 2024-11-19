/*
2461. Maximum Sum of Distinct Subarrays With Length K

You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:

The length of the subarray is k, and
All the elements of the subarray are distinct.
Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.



  */


class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long answer = 0;
        for(int i=0;i<= n-k; i++){
            long long sum = 0;
            unordered_map<int,int> hashmap;
            for(int j=i;j<i+k;j++){
                // if we found any element in hashmap
                if(hashmap.find(nums[j]) != hashmap.end()){
                    sum = 0;
                    break;
                }
                hashmap[nums[j]] = 1;
                sum+=nums[j];
            }
            answer = sum > answer ? sum : answer;
        }
        return answer;
    }
};
