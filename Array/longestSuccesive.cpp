#include<bits/stdc++.h>
using namespace std;

int brute_longestSuccessiveSubseq(vector<int> nums){
    sort(nums.begin(), nums.end());
    int last_smaller = INT_MIN;
    int count = 0;
    int n = nums.size();
    int longest = 1;
    for(int i : nums){
        if(i-1 == last_smaller){

            count += 1;
            last_smaller = i;
        }else if(i != last_smaller){
            // reassigning and starting counting again
            count = 1;
            last_smaller = i;
        }
        longest = max(longest, count);
    }
    return longest;
}

int main(){
    vector<int> vec = {1,4,2,5,101,100,99,97,98};
    cout<<brute_longestSuccessiveSubseq(vec);
}