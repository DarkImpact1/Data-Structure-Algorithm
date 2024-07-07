#include<bits/stdc++.h>
using namespace std;

int brute_subarrayXorK(vector<int> nums, int k){
    int n= nums.size();
    int count = 0;
    for(int i=0;i <n; i++){
        for(int j=i;j<n;j++){
            int num = 0;
            for(int k = i; k<=j;k++){
                num = num ^ nums[k];
            }
            if(num == k) count++;
        }
    }
    return count;
}
int better_subarrayXorK(vector<int> nums, int k){
    int n= nums.size();
    int count = 0;
    for(int i=0;i <n; i++){
        int xori = 0;
        for(int j=i;j<n;j++){
            xori = xori ^ nums[j];
        }
        if(xori == k) count++;
    }
    return count;
}
int optimal_subarrayXorK(vector<int> nums, int k){
    int n= nums.size();
    int count = 0;
    for(int i=0;i <n; i++){
        int xori = 0;
        for(int j=i;j<n;j++){
            xori = xori ^ nums[j];
        }
        if(xori == k) count++;
    }
    return count;
}




int main() {
    vector<int> vec1={4,2,2,6,4};
    cout<<brute_subarrayXorK(vec1 , 6)<<endl;

    return 0;
}