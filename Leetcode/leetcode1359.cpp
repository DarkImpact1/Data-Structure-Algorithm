/*
1359. Count All Valid Pickup and Delivery Options
Given n orders, each order consists of a pickup and a delivery service.
Count all valid pickup/delivery possible sequences such that delivery(i) is always after of pickup(i). 
Since the answer may be too large, return it modulo 10^9 + 7.
*/

class Solution {
public:
    int countOrders(int n) {
        // ans = n! * 1*3*5.......(2*i-1)
        int m = 1e9+7;
        long ans=1;
        for(int i=1;i<=n;i++){
            ans = (ans*i)%m;
            ans = (ans*(2*i-1))%m;
        }
        return ans;
    }
};

