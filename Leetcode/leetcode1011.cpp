/*
1011. Capacity To Ship Packages Within D Days
Solved
Medium
Topics
Companies
Hint
A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

 
*/

// min num of days will be the max of wieght present in the array then we can ship the weights in nums.size() days 
// max num of days will be be total sum of wieght in the array then we can ship all the wieghts in 1 days
// now apply the binary search on number to find the ninimum number of days
class Solution {
public:
    int noDayReq(vector<int> &nums, int capacity){
        int numDay = 1, weightSum = 0;
        for(auto w : nums){
            if((w + weightSum) > capacity){
                numDay++;
                weightSum = w;
            }else{
                weightSum += w;
            }
        }
        return numDay;
    }
    void updateMinMax(vector<int> &weights, int &minW, int &maxW){
        int totalW = 0;
        for(auto w : weights){
            if (w > minW) minW = w;
            totalW += w;
        }
        maxW = totalW;
    }
    int shipWithinDays(vector<int>& weights, int days){
        int minW = INT_MIN, maxW;
        updateMinMax(weights, minW, maxW);
        while(minW <= maxW){
            int midW = (minW+maxW)/2;
            int numDay = noDayReq(weights, midW);
            if(numDay <= days){
                maxW = midW-1;
            }else{
                minW = midW+1;
            }
        }
        return minW;
        
    }
};
