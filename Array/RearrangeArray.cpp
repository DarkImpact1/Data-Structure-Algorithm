#include<bits/stdc++.h>
using namespace std;

// brute force solution 
vector<int> rearrangeArray(vector<int>& nums) {
    vector<int> pos;
    vector<int> neg;
    vector<int> f;
    for(int i: nums){
        if(i > 0){
            pos.push_back(i);
        }else{
            neg.push_back(i);
        }        
    }
    for(int i=0;i<pos.size();i++){
        f.push_back(pos[i]);
        f.push_back(neg[i]);
    }
    return f;
    }

vector<int> rearrangeArray1(vector<int> &nums){
    int pos=0, neg=1;
    vector<int> answer(nums.size());
    for(int i=0; i<nums.size();i++){
        if(nums[i]<0){
            answer[neg] = nums[i];
            neg+=2;
        }else{
            answer[pos] = nums[i];
            pos+=2;
        }
    }
    return answer;
}

int main(){
    vector<int> nums = {-3,1,2,-5,2,-4};
    for(auto it : rearrangeArray1(nums)){
        cout<<it <<" ";
    }
}