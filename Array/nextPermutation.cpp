#include<bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(vector<int> nums){
    int index = -1;
    int n = nums.size();
    for(int i= n-2; i>=0; i-- ){
        if(nums[i] < nums[i+1]){
            index = i;
            break;
        }
    }
}