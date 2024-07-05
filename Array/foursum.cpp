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
// optimal approach  using three two for loop and two pointer approach but we have to sort the array to avoid extra hash set and duplication
vector<vector<int>> optimal_fourSum(vector<int> nums, int target){
    vector<vector<int>> result;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for(int i = 0 ; i< n; i++){
        // skipping duplicates for the ith index
        if(i >0 && nums[i] == nums[i-1]) continue;
        for(int j = i+1; j <n ; j++){
            // skipping duplicates
            if(j> i+1 && nums[j] == nums[j-1]) continue;
            int k = j+1;
            int l = n-1;
            while(k < l){
                int sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];
                if(sum == target){
                    vector<int> temp = {nums[i],nums[j], nums[k],nums[l]};
                    result.push_back(temp);
                    k++;
                    l--;
                    // skipping duplicates
                    while(k < l && nums[k] == nums[k-1]) k++;
                    while(k< l && nums[l] == nums[l+1]) l--;
                }else if(sum < target){
                    k++;
                }else{
                    l--;
                }
                
            }
            
        }
    }
    return result;
}
int main(){
    vector<int> vec = {1,0,-1,0,-2,2};
    int target = 0;
    vector<vector<int>> res = optimal_fourSum(vec,target);
    for(auto array : res){
        for(auto item : array){
            cout<<item << " ";
        }
        cout<<endl;
    }
        
}