#include <bits/stdc++.h>
using namespace std;

// return a unique triplet whose sum is 0 from the given array 
vector<vector<int>> optimal_threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for(int i=0;i<n;i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int j = i+1;
            int k = n-1;
            while(j < k){
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                if(sum == 0){
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    result.push_back(temp);
                    j++;
                    k--;
                    while(j < k && nums[j] == nums[j-1]) j++;
                    while(j < k && nums[k] == nums[k+1]) k--;

                }
                else if(sum < 0) j++;
                else k--;
            }
        }
        return result;
}

int main(){
    vector<int> vec = {-1,0,1,2,-1,-4};
    int target = 0;
    vector<vector<int>> res = optimal_threeSum(vec);
    for(auto array : res){
        for(auto item : array){
            cout<<item << " ";
        }
        cout<<endl;
    }
        
}