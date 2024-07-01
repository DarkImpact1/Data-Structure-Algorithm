#include<bits/stdc++.h>
using namespace std;


vector<int> extractLeader(vector<int>& nums){
    int n =nums.size()-1;
    int mm = INT_MIN;
    vector<int> res;
    for(int i =n; i>=0; i-- ){
        if(nums[i] > mm){
            res.push_back(nums[i]);
            mm = nums[i];
        }
    }
    reverse(res.begin(),res.end());
    return res;
}

int main(){
    vector<int> vec = {10,22,12,3,0,6};
    for(int i : extractLeader(vec)){
        cout<<i <<" ";
    }
}