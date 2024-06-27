#include <bits/stdc++.h>
using namespace std;
/*
whether there are two element which can yeild sum k;
*/
string twoSumExist(int n, vector<int> vec, int k){
    map<int, int> mpp;
    for(int i=0; i<n;i++){
        int a = vec[i];
        int required = k-a;
        if(mpp.find(required) != mpp.end()){
            return "yes"; // for index return {mpp[required],i}
        }
        mpp[a] = i;
    }
    return "No";
}

// two pointer approach
string sumExist(int n, vector<int> nums, int k){
    int left = 0, right = n-1;
    sort(nums.begin(), nums.end());
    while(left < right){
        
    }
}
int main(){
    vector<int> vec = {2,4,3,5,6,8};
    cout<<twoSumExist(6,vec,12);
    
}