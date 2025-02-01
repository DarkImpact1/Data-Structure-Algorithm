/*
216. Combination Sum III

Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, 
and the combinations may be returned in any order.

 

Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.
Example 2:

*/

// general one 
    void com(vector<int>& nums,int i, int k, int target, vector<int> temp,vector<vector<int>>& result){
        if(temp.size() == k){
            if(target == 0){
                result.push_back(temp);
            }
            return;
        }
        
        if (i >= nums.size()) {
            return;
        }
        if(nums[i] <= target){
            temp.push_back(nums[i]);
            com(nums,i+1,k,target-nums[i],temp,result);
            temp.pop_back();
        }
        com(nums,i+1,k, target,temp,result);
    }


// optimised one 
void com(int num, int k, int target, vector<int>& temp, vector<vector<int>>& result) {
    if (temp.size() == k) {
        if (target == 0) {
            result.push_back(temp);
        }
        return;
    }

    if (num > 9) {
        return;
    }

    if (num <= target) {
        temp.push_back(num);
        com(num + 1, k, target - num, temp, result);
        temp.pop_back();
    }

    com(num + 1, k, target, temp, result);
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> temp;
    vector<vector<int>> result;
    com(1, k, n, temp, result);
    return result;
}
