/*
reverser the array: two method one take O(n) another is doing it recursively
*/

// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
void reverseArray(vector<int>& nums){
    int low =0,high = nums.size()-1;
    while(low<high){
        swap(nums[low],nums[high]);
        low++;
        high--;
    }
}

void reverseArrayRecursively(vector<int>& nums, int low, int high){
    if(low >= high){
        return;
    }
    swap(nums[low],nums[high]);
    reverseArrayRecursively(nums,low+1, high-1);
    
}

int main() {
    vector<int> arr = {1,2,3,4};
    reverseArray(arr);
    for(auto it : arr){
        cout<<it<<" ";
    }
    cout<<endl;
    reverseArrayRecursively(arr,0,arr.size()-1);
    for(auto it : arr){
        cout<<it<<" ";
    }
    

    return 0;
}
