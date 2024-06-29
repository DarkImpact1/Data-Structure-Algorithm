#include <bits/stdc++.h>
using namespace std;

vector<int> find(vector<int> nums){
    int n = nums.size()/3;
    vector<int> result;
    map<int,int> mpp;
    for(int i: nums){
        mpp[i]++;
    }
    for(auto it : mpp){
        if(it.second > n){
            result.push_back(it.first);
        }
    }
    return result;
}
int main() {
    vector<int> arr = {1,2};
    for(int i : find(arr)){
        cout<<i<<" ";
    }

    return 0;
}