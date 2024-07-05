#include <bits/stdc++.h>
using namespace std;

// brute force using four for loop 
vector<vector<int>> fourSum(vector<int> nums, int target){
    set<vector<int>> st;
    int n = nums.size();
    for(int i = 0 ; i< n; i++){
        for(int j = i+1; j <n ; j++){
            for(int k = j+1; k < n; k++){
                for(int l = k+1; l<n; l++){
                    int sm = nums[i] + nums[j];
                    sm += nums[k];
                    sm += nums[l];
                    if(sm == target){
                        vector<int> temp = {nums[i], nums[j],nums[k],nums[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> result(st.begin(), st.end());
    return result;
}

// brute force using three for loop for fourth we'll go fourth = target - nums[i]+ nums[j]+ nums[k]
vector<vector<int>> better_fourSum(vector<int> nums, int target){
    set<vector<int>> st;
    int n = nums.size();
    for(int i = 0 ; i< n; i++){
        for(int j = i+1; j <n ; j++){
            set<int> hashset;
            for(int k = j+1; k < n; k++){
                    int sm = nums[i] + nums[j];
                    sm += nums[k];
                    int fourth = target - sm;
                    if(hashset.find(fourth) != hashset.end()){
                        vector<int> temp = {nums[i], nums[j],nums[k],fourth};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                    hashset.insert(nums[k]);
            }
        }
    }
    vector<vector<int>> result(st.begin(), st.end());
    return result;
}

int main(){
    vector<int> vec = {1,0,-1,0,-2,2};
    int target = 0;
    vector<vector<int>> res = better_fourSum(vec,target);
    for(auto array : res){
        for(auto item : array){
            cout<<item << " ";
        }
        cout<<endl;
    }
        
}