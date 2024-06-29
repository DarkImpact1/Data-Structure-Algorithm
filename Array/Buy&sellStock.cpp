#include<bits/stdc++.h>
using namespace std;

int sellStock(vector<int> nums){
    int mini = nums[0], max_profit = 0;
    for(int i=1; i<nums.size();i++){
        int cost = nums[i] - mini;
            max_profit = (cost > max_profit) ? cost : max_profit;
            mini = (mini < nums[i]) ? mini : nums[i];
    }
    return max_profit;
}


// ANother solution 
int sellStock1(vector<int> price){
    int buy=0, sell=1;
    int profit=0;
    while(sell < price.size()-1){
        if(price[sell]- price[buy] < 0){
            buy = sell;
        }else{
            profit = max(profit, price[sell]- price[buy]);
        }
        sell++;
    }
    return profit;
}

int main() {
    vector<int> prices = {7,6,4,3,1};
    cout<<sellStock(prices);
    return 0;
}