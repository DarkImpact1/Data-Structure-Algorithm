// Subset of given array 

class Solution {
public:
    vector<vector<int>> answer;

    void generateSubset(vector<int>& nums,int pos, vector<int>& subs){
        if(pos == nums.size()){
            answer.push_back(subs);
            return;
        }
        

        // take
        subs.push_back(nums[pos]);
        generateSubset(nums,pos+1, subs);
        
        // not take means remvoe the top element
        subs.pop_back();
        generateSubset(nums,pos+1, subs);
        
        
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subs;
        generateSubset(nums, 0, subs);
        return answer;
        

    }
};
