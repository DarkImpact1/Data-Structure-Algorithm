#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int>& weight, vector<int>& value, int capacity, int n) {
    if (n < 0 || capacity == 0) {
        return 0;
    }

    if (weight[n] <= capacity) { 
        return max(value[n] + knapsack(weight, value, capacity - weight[n], n - 1), knapsack(weight, value, capacity, n - 1));
    }

    return knapsack(weight, value, capacity, n - 1);
}

int main() {
    vector<int> weight = {2, 3, 4, 5,8};  
    vector<int> value = {3, 4, 18, 6,20};  
    int capacity = 8;  
    int n = weight.size()-1; 

    int max_value = knapsack(weight, value, capacity, n);
    cout << "Maximum value in knapsack: " << max_value << endl;

    return 0;
}
