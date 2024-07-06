#include<bits/stdc++.h>
using namespace std;
void brute_merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
    vector<int> svector(m+n);
    int left=0, right = 0,index = 0;
    while(left < m && right < n){
        if(nums1[left] <= nums2[right]){
            svector[index++] = nums1[left++];
        }else{
            svector[index++] = nums2[right++];
        }
    }
    while(left < m){
        svector[index++] = nums1[left++];
    }
    while(right < n){
        svector[index++] = nums2[right++];
    }
    for(int i = 0; i < m+n; i++){
        nums1[i] = svector[i];
    }
}
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
    
}
int main() {
    vector<int> vec1={1,2,3,0,0,0,0};
    vector<int> vec2 = {2,5,6,7};
    int m = 3;
    int n = 4;
    brute_merge(vec1,m,vec2,n);
    for(auto it : vec1){
        cout<<it <<" ";
    }

    return 0;
}
