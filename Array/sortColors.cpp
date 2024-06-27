#include <bits/stdc++.h>
using namespace std;
/*
Leetcode 75
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.
*/
void sortColors(vector<int> &vec){
    int n = vec.size();
    int r =0, w=0;
    for(int i : vec){
        if(i == 0){
            r++;
        }else if(i == 1){
            w++;
        }
    }
    for(int i=0; i<n;i++){
        if(i < r){
            vec[i] =0;
        }else if(i >= r && i < (r+w)){
            vec[i] = 1;
        }else{
            vec[i] = 2;
        }
    }
}
int main(){
    vector<int> vec = {2,0,1,0};
    sortColors(vec);
    for(int i: vec){
        cout<<i <<" ";
    }
    
}