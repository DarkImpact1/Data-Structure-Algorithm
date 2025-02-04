// number of subsequence that can yeild sum of min and max of arr  <= target but 


#include <bits/stdc++.h>
using namespace std;

// O(n)
int findSum(vector<int>& nums){
    if(nums.size() == 0)return 0;
    int mini = INT_MAX, maxi=INT_MIN;
    for(auto it: nums){
        if(it < mini) mini = it;
        if(it > maxi) maxi = it;
    }
    return mini +  maxi;
}

// O(2^n)
void generateSub(int i,vector<int>&nums, vector<int> temp,int &count, int target){
    
    if(i == nums.size()){
        int s = findSum(temp);
        if(s <= target){
            count++;
        }
        return;
    }
    
    temp.push_back(nums[i]);
    generateSub(i+1,nums,temp,count,target);
    
    temp.pop_back();
    generateSub(i+1,nums, temp,count,target);
}

// n*2^n
int numSubseq(vector<int>& nums, int target) {
    int i=0, count=0;
    vector<int> temp;
    generateSub(i,nums,temp,count,target);
    return count-1;
}

int main() {
    vector<int> nums = {3,5,6,7};
    cout<<numSubseq(nums, 9);
    
    return 0;
}
