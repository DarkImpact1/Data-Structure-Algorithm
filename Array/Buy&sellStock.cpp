#include<bits/stdc++.h>
using namespace std;

int sellStock(vector<int> nums){
    int mini = nums[0], max_profit = 0;
    for(int i=1; i<nums.size();i++){
        int cost = nums[i] - mini;
        max_profit = max(cost,max_profit);
        mini = min(mini,nums[i]);
    }
    return max_profit;
}


int main() {
    vector<int> prices = {7,6,4,3,1};
    cout<<sellStock(prices);
    return 0;
}