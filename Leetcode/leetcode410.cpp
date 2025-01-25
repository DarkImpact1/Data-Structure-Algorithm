/*
410. Split Array Largest Sum
Hard
Topics
Companies
Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.

*/

// THIS PROBLEM IS SAME AS THE BOOK ALLOCATION AND PAINTER'S PROBLEM SO MAKE SURE YOU REVISIST BOTH PROBLEM AND REVISE THE CONCEPT
class Solution {
public:
    void updateLowHigh(vector<int>& nums, int &low, int &high){
        int s = 0;
        for(auto n : nums){
            if( n > low)  low = n;
            s+= n;
        }
        high = s;
    }

    int numSubArr(vector<int> & nums, int minSum){
        int numSub = 1, add = 0;
        for( auto n : nums){
            if ( (add + n) > minSum){
                    numSub++;
                    add = n;
            }else{
                add += n;
            }
        }
        return numSub;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = INT_MIN, high = 0;
        updateLowHigh(nums, low, high);
        while(low <= high){
            int midSum = (low+high)/2;
            int numSubPossible = numSubArr(nums, midSum);
            if(numSubPossible > k) low = midSum+1;
            else high = midSum -1;
        }
        return low;
    }
};

