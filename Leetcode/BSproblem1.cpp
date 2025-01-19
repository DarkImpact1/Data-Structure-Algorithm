/*
find the kth element from the unsorted array without using extra space and remember you can only read the array

*/
/*
so here's the logic
find min and max 
min starting and max high range rahegi. then mid cal kro frr check kro kitne element mid < hai to iska mtlb hamara answer mid ke right side 100% hai
leking agar vo number of element >= k aata hai to hamra answer mid bhi ho skta hai jiske liye hum dobarra se check mid-1 ke liye check krenge
aur agar number of element <= form mid-1 agar < k aata hai to hmara answer mid hai nhi to hum high ko mid-1 kr denge 
*/



#include <bits/stdc++.h>
using namespace std;
int countNumEleLess(vector<int> &nums, int n){
    int count = 0;
    for(auto it: nums){
        if(it <= n) count++;
    }
    return count;
}
int leftEnd(vector<int> &nums){
    int mini = INT_MAX;
    for(auto it : nums){
        if(it < mini){
            mini = it;
        }
    }
    return mini;
    
}
int rightEnd(vector<int> &nums){
    int maxi = INT_MIN;
    for(auto it : nums){
        if(it > maxi){
            maxi = it;
        }
    }
    return maxi;
    
}
int findKthElement(vector<int> &nums, int k){
    int low = leftEnd(nums);
    int high = rightEnd(nums);
    while(low <= high){
        int mid = (low+high)/2;
        int n = countNumEleLess(nums, mid);
        if(n >= k){
            int reconfirm = countNumEleLess(nums,mid-1);
            if(reconfirm < k) return mid;
            high = mid -1;
        }else{
            low = mid+1;
        }
    }
    return low;
}
int main() {
    vector<int> nums = {1,2,4,1,5,5,10,3};
    cout<<findKthElement(nums,4);
    return 0;
}
