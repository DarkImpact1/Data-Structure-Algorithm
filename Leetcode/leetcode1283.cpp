/*
1283. Find the Smallest Divisor Given a Threshold
Solved
Medium
Topics
Companies
Hint
Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

The test cases are generated so that there will be an answer.
  */

class Solution {
public:
    void updateHigh(vector<int> &bloomDay, int &high){
        for(auto it : bloomDay){
            if(it > high) high = it;
        }
    }
    int sumDivisor(vector<int> &nums, int divisor){
        int res = 0;
        for(auto num : nums){
            res += (num+divisor-1)/divisor;
        }
        return res;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = INT_MIN;
        updateHigh(nums, high);
        while(low < high){
            int divisor = (low+high)/2;
            int result = sumDivisor(nums, divisor);
            if(result > threshold){
                low = divisor+1;
            }else{
                high = divisor;
            }
        }
        return high;
    }
};
