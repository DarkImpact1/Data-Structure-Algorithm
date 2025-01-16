/*
34. Find First and Last Position of Element in Sorted Array


Given an array of integers nums sorted in non-decreasing order,
find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.
  */




class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int lower = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int upper = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(lower == upper){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        ans.push_back(lower);
        ans.push_back(upper-1);
        return ans;
    }
};
