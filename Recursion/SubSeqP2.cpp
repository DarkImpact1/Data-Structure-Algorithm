/*

1498. Number of Subsequences That Satisfy the Given Sum Condition
You are given an array of integers nums and an integer target.

Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum element on it is less or equal 
to target. Since the answer may be too large, return it modulo 109 + 7.

 
*/

// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

    int findSum(vector<int>& nums){
        if(nums.size() == 0)return 0;
        int mini = INT_MAX, maxi=INT_MIN;
        for(auto it: nums){
            if(it < mini) mini = it;
            if(it > maxi) maxi = it;
        }
        return mini +  maxi;
    }
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
    
        
    
    // better approach two pointer in sorted to count all the possible combination that can yeild sum <= k
    
    
    int calPow(int a, int x,int m){
        int ans = 1;
        while(x > 0){
            ans = ((ans%m)*(a%m))%m;
            x--;
        }
        return ans;
    }
    
    // O(n*log(n) * n * n
    int numSubSeq(vector<int>& nums, int target){
        sort(nums.begin(), nums.end());
        int m = 1e9+7;
        int ans = 0;
        int l = 0, r = nums.size()-1;
        while(l<=r){
            if((nums[l]+nums[r]) <= target){
                ans = ((ans%m) + (calPow(2,r-l,m)%m))%m;
                l++;
            }else{
                r--;
            }
        }
        return ans;
    }



int main() {
    vector<int> nums = {2,3,3,4,6,7};
    cout<<numSubSeqq(nums, 12);

    return 0;
}


// optimised solution precompute the power of 2 and then use them
/*
Logic n

number of subsequece = 2^n so that the reaison we were calculation power of 2

now if [1,2,3] in this sub sum(min,max) = 4 so totol number of subseq that can yeild sum <= 4 will 2^3 i.e. 8 
So sort the array ans use two pointer of binary search to find the max and min ele whose sum <= k then 
increase the count += 2^(j-i) that we already have computed

 */


class Solution {
public:
     //                      arr      size   modulus
void preCompute(vector<int>& power, int n,int m){
    for (int i = 0; i < n; i++) {
            if (i == 0) {
                power[i] = 1;
            } else {
                power[i] = (2LL * power[i - 1]) % m;
            }
        }  
}
int modAdd(int a, int b, int m){
    return ((a%m)+(b%m))%m;
}
int numSubseq(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<int> power(nums.size());
    int m = 1e9 + 7;
    preCompute(power,nums.size(),m);
    int ans = 0;
    int left = 0, right = nums.size()-1;
    while(left <= right){
        if((nums[left]+ nums[right]) <= target){
            ans = modAdd(ans,power[right-left],m);
            left++;
        }else{
            right--;
        }
    }
    return ans;
}
};
