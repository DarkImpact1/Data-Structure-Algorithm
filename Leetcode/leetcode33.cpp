/*
search in sorted array
*/


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        int ans = -1;
        while(low <= high){
            int mid = (low+ high)/2;
            if(nums[mid] == target) ans = mid;
            // left portion is sorted
            if(nums[low] <= nums[mid]){
              // check where your answer lies in sorted portion if it is then move high to mid -1
                if(nums[low] <= target && target <= nums[mid]){
                    high = mid -1;
                }else{
                    low = mid +1;
                }
            }
            else{
              // means right protion is sorted not check if answer lies is right part if it is then move low to mid+1
                if(nums[mid] <= target && target <= nums[high]){
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }
        }
        return ans;
    }
};
