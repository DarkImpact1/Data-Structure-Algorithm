/*
find first and last occurrence of odd and even number given an array [e,e,e,e,o,o,o,o,o]
*/


// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

int getFirstOddNum(vector<int> & nums){
    int left = 0;
    int right = nums.size()-1;
    while(left <= right){
        int mid =(left + right ) /2;
        if(nums[mid]%2 == 0){
            left = mid+1;
        }else{
            if(mid == 0 || nums[mid-1]%2 == 0 ) return nums[mid];
            right = mid -1;
        }
    }

    return -1;
}
int getLastEvenNum(vector<int> &nums){
    int left = 0, right = nums.size()-1;
    while(left <= right){
        int mid = (left+right)/2;
        if(nums[mid]%2 == 0){
            if(mid == nums.size()-1 || nums[mid+1]%2 !=0) return nums[mid];
            left = mid +1;
        }else{
            right = mid -1;
        }
    }
    return -1;
}
int main(){
    vector<int> vec = {1,3,5,7};
    cout<<getFirstOddNum(vec)<<endl;
    cout<<getLastEvenNum(vec)<<endl;
}


