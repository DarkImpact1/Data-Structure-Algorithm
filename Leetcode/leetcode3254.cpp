/*
Find the Power of K-Size Subarrays

You are given an array of integers nums of length n and a positive integer k.

The power of an array is defined as:

Its maximum element if all of its elements are consecutive and sorted in ascending order.
-1 otherwise.
You need to find the power of all 
subarrays
 of nums of size k.

Return an integer array results of size n - k + 1, where results[i] is the power of nums[i..(i + k - 1)].
  */



class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> answer;
        int len = 0;
        for(int i=0;i<=nums.size()-k;i++){
            vector<int> slice(nums.begin()+i,nums.begin()+k+i);
            if(isSorted(slice,k)) answer.push_back(slice.back());
            else answer.push_back(-1);
        }
        return answer;
    }

    bool isSorted(vector<int>& nums,int k){
        for(int i=1; i<k; i++){
            if(nums[i]-1 != nums[i-1]){
                return false;
            }
        }
        return true;
    }
};
