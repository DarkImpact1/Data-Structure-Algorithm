// Merge sort algorithm 

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int left, int mid , int right){
    vector<int> temp;
    int l = left, r = mid+1; 
    while(l <= mid && r <= right){
        if(arr[l]<= arr[r]){
            temp.push_back(arr[l]);
            l++;
        }else{
            temp.push_back(arr[r]);
            r++;
        }
    }
    while(l <= mid){
        temp.push_back(arr[l++]);
    }
    while(r <= right){
        temp.push_back(arr[r++]);
    }
    for(int i=left; i<=right; i++){
        arr[i] = temp[i-left];
    }
    
}

void mergeSort(vector<int>& arr, int left, int right){
    if(left >= right){
        return;
    }
    int mid = (left+right)/2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr, left, mid, right);
}


int main() {
    vector<int> nums = {4,3,5,6,2,3,1,7};
    mergeSort(nums,0,nums.size()-1);
    for(auto i : nums){
        cout<<i <<" ";
    }

    return 0;
}
