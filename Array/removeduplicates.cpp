/*
Problem : Remove duplicates from the sorted order array and return total number of unique element;
*/


#include <bits/stdc++.h>
using namespace std;



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
int main() {
    vector<int> vec  = {0,1,1,1,1,2,2,3,3,4,5};
    int n = removeDuplicates(vec);
    for(int i=0; i<n; i++){
        cout<<vec[i]<<" ";
    }
    return 0;
}