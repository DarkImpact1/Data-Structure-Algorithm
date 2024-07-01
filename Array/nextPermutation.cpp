#include<bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) {
        int index = -1;
        int n = nums.size();
        
        // Find the first index where nums[i] < nums[i+1] from the end
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                index = i;
                break;
            }
        }
        
        // If no such index exists, reverse the entire array
        if(index == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        // Find the smallest number larger than nums[index] to swap with
        for(int i = n - 1; i > index; i--) {
            if(nums[i] > nums[index]) {
                swap(nums[i], nums[index]);
                break;
            }
        }
        
        // Reverse the part of the array after the index
        reverse(nums.begin() + index + 1, nums.end());
    }

int main() {
    vector<int> vec = {1,2,3};
    nextPermutation(vec);
    for(int i: vec){
        cout<<i<<" ";
    }
    return 0;
}