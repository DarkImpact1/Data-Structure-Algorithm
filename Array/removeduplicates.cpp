/*
Problem : Remove duplicates from the sorted order array and return total number of unique element;
*/


#include <bits/stdc++.h>
using namespace std;


// two pointer approach
int removeDuplicates(vector<int>& nums) {
        int i=0;
        for(int j = 1; j< nums.size(); j++){
            if(nums[j] != nums[i]){
                nums[i+1] = nums[j];
                i++;
            }
        }
        return i+1;
    }
// Another method
int removeDuplicates2(vector<int> &nums){
    int unique = 1;
    for(int i = 1;i<nums.size(); i++){
        if(nums[i] != nums[i-1]){
            nums[unique] = nums[i];
            unique++;
        }
    }
    return unique;
}
int main() {
    vector<int> vec  = {0,1,1,1,1,2,2,3,3,4,5};
    int n = removeDuplicates2(vec);
    for(int i=0; i<n; i++){
        cout<<vec[i]<<" ";
    }
    return 0;
}