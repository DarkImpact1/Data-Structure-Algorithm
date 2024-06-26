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
        for(int j=i; j<n; j++){
            s += nums[j];
            m = max(s,m);
        }
    }
    return m;
}

// Kadane's algorithm for max_subarray O(n)
int optimal_max_Subarr(vector<int> nums){
    int m=nums[0];
    int s=0;
    for(int i=0; i<nums.size(); i++){
        s += nums[i];
        m = max(s,m);
        if(s < 0){
            s = 0;
        }
    }
    return m;
}

int main() {
    vector<int> vec = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<optimal_max_Subarr(vec);
    return 0;
}