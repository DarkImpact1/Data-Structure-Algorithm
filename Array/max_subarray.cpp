// Max subarray problem
#include<bits/stdc++.h>
using namespace std;

 // time complexity O(n**3)
int brute_max_Subarr(vector<int> nums){
    int n=nums.size();
    // because array will contain atleast one element
    int m=nums[0];
    for(int i=0;i<n;i++){
        for(int j=0; j<n; j++){
            int s=0;
            for(int k=i; k<j; k++){
                s += nums[k];
            }
            if(s > m){
                m = s;
            }
        }
    }
    return m;
}


// time complexity O(n**2)
int better_max_Subarr(vector<int> nums){
    int n=nums.size();
    // because array will contain atleast one element
    int m=nums[0];
    for(int i=0;i<n;i++){
        int s=0;
        for(int j=0; j<n; j++){
            if(i == j) continue;
            s += nums[j];
            m = max(s,m);
        }
    }
    return m;
}
int main() {
    vector<int> vec = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<brute_max_Subarr(vec);
    return 0;
}