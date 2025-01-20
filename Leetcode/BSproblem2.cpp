/*
Maximise K such that none of the subarray of size k has sum > X;

concept : 
range of k will be from 0 to size of array, so calculate mid and then check for mid
if mid = 3 give sum > X then all the value > 3 will give sum of subarray > X so answer lies in range < 3 move high = mid -1;
if mid = 2 gives sum <= X then it might be the case your answer is 2 so instatnly check for mid+1 and if sum > X then your answer is 2;

*/

#include <bits/stdc++.h>
using namespace std;
// sliding window to check min sum of subarray of size k;
int sumSubarrSizeK(vector<int> &nums, int k){
    int mini = INT_MAX;
    int total = 0;
    for(int i=0; i<k;i++){
        total+=nums[i];
    }
    if(total < mini) mini= total;
    for(int i=k; i<nums.size();i++){
        total+= nums[i];
        total-= nums[i-k];
        if(total < mini) mini = total;
    }
    return mini;
}
// bruteforce approach which will take time complexity of O(N*K);
int maxKSubArrSumLessEqualX(vector<int> &nums, int X){
    for(int i=1; i<nums.size();i++){
        cout<<"Minimum sum for k = "<<i<<endl;
        int k = sumSubarrSizeK(nums,i);
        cout<<"ans =  "<<k<<endl;
        if(k > X) return i-1;
    }
    return -1;
}
int findSum(vector<int>& nums){
    int x = 0;
    for(auto it: nums){
        x+= it;
    }
    return x;
}
// using binary search O(n* log n)

int optMaxKSubArrSumLessEqualX(vector<int>& nums, int X){
    if(findSum(nums) == X) return nums.size();// for edge case
    int low = 0, high = nums.size();
    while(low <= high){
        int mid = (low+high)/2;
        int min_sum_size_mid = sumSubarrSizeK(nums,mid);
        if(min_sum_size_mid > X){
            high = mid -1;
        }else{
            int recheck = sumSubarrSizeK(nums,mid+1);
            if(recheck > X) return mid;
            low = mid+1;
        }
    }
    return -1;
}

int main() {
    vector<int> arr={1,1,1,1,1,1,1,1,1};
    cout<<optMaxKSubArrSumLessEqualX(arr,0)<<endl;
    
    
    return 0;
}
