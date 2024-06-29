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



int main(){

}