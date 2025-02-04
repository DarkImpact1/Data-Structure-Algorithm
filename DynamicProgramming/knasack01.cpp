#include <iostream>
#include <vector>

using namespace std;

// simple recursion
int knap(vector<int>& wt, vector<int>& val, int cap, int n){
    if(cap == 0 || n == 0){
        return 0;
    }
    
    if(wt[n-1] <= cap){
        int include = val[n-1] + knap(wt, val, cap - wt[n-1], n-1);
        int not_inc = knap(wt, val, cap, n-1);
        return max(include, not_inc);
    }
    return knap(wt, val, cap, n-1);
}

// Memoization
int memKnap(vector<int>&wt, vector<int>&val, int cap, int n, vector<vector<int>>&dp){
    if(cap == 0 || n == 0){
        return 0;
    }
    if(dp[n][cap] != -1){
        return dp[n][cap];
    }
    
    if(wt[n-1] <= cap){
        int inc = val[n-1] + memKnap(wt,val,cap-wt[n-1],n-1,dp);
        int n_inc = memKnap(wt,val,cap,n-1,dp);
        int max_pro = max(inc,n_inc);
        dp[n][cap] = max_pro;
        return max_pro;
    }
    return dp[n][cap] = memKnap(wt,val,cap,n-1,dp);

}

// top down approach
int knapSack(int cap, vector<int>& val, vector<int>& wt){
    int size = wt.size();
    vector<vector<int>> topDown(size+1,vector<int>(cap+1,0));
    
    for(int n = 1; n<size+1; n++){
        for(int c = 1; c<cap+1; c++){
            if(wt[n-1] <= c){
                int inc = val[n-1] + topDown[n-1][c - wt[n-1]];
                int n_inc = topDown[n-1][c];
                topDown[n][c] = max(inc, n_inc);
            }else{
                topDown[n][c] = topDown[n-1][c];
            }
        }
    }
    return topDown[size][cap];
}

int main() {
    vector<int> weights = {2, 3, 4, 5};
    vector<int> values = {3, 4, 5, 6};
    
    int capacity = 5;
    int n = weights.size();
    vector<vector<int>> dp(n+1,vector<int>(capacity+1,-1));

    int maxProfit = knapSack(capacity, values, weights);
    cout << "Maximum Profit: " << maxProfit << endl;

    return 0;
}
