/*
Description : 
  416. Partition Equal Subset Sum

Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements
in both subsets is equal or false otherwise.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 
*/


/*
Logic 
i
if total sum  = even then it is possible to get two subseq that can have equal sum
  find if any subsequence can generate a subsequence of sum = total/2 then return "true" else false;
  
else not possible 

*/



class Solution {
public:

    bool canPart(vector<int>& nums, int k, int n){
        
        vector<vector<bool>> t(n+1,vector<bool>(k+1));
        int r = 0;
        while(r < n+1){
            t[r][0] = true;
            r++;
        }
        int c = 1;
        while(c < k+1){
            t[0][c] = false;
            c++;
        }
        for(int i = 1; i < n+1; i++){
            for(int j = 1; j< k+1; j++){
                if(nums[i-1] <= j){
                    bool inc = t[i-1][j-nums[i-1]];// include the el
                    bool n_inc = t[i-1][j]; // not inc ele
                    t[i][j] = inc || n_inc;
                }else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        
        return t[n][k];
    }

    bool canPartition(vector<int>& nums) {
        int total =0;
        for(auto it : nums){
            total += it;
        }
        // If the total sum is odd, it's impossible to divide into two equal subsets
        if (total % 2 != 0) {
            return false;
        }

        int n = nums.size();
        int half = total / 2; 
        return canPart(nums,half,n); 
    }
};

