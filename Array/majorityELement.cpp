// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

// bruteforce method On**2)
int brute_find_majority(vector<int> nums){
    int n = nums.size();
    for(int i=0;i<n;i++){
        int c=0;
        for(int j=0;j<n;j++){
            if(nums[j]==nums[i]){
                c++;
            }
        }
        if(c> n/2){
            return nums[i];
        }
    }
    return -1;
}

// better solution using hashmap NLogN + (N)
int better_find_majority(vector<int> nums){
    map<int,int> mpp;
    for(int i: nums){
        mpp[i]++;
    }
    for(auto i : mpp){
        if(i.second > nums.size()/2){
            return i.first;
        }
    }
    return -1;
}
int main() {
    vector<int> vec ={2,2,1,1,1,2,2};
    cout<<better_find_majority(vec);
    return 0;
}