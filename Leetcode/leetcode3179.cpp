/*

3179. Find the N-th Value After K Seconds

You are given two integers n and k.
Initially, you start with an array a of n integers where a[i] = 1 for all 0 <= i <= n - 1.
After each second, you simultaneously update each element to be the sum of all its preceding elements
plus the element itself. For example, after one second, a[0] remains the same, a[1] becomes a[0] + a[1], a[2]
becomes a[0] + a[1] + a[2], and so on.

Return the value of a[n - 1] after k seconds.

Since the answer may be very large, return it modulo 109 + 7.

  */



class Solution {
public:
    int m = 1e9+7;
    int valueAfterKSeconds(int n, int k) {
    vector<int> sol(n,1);
    for(int i=0; i<k; i++){
        for(int j=1; j<n; j++){
                sol[j] = ((sol[j]%m)+(sol[j-1]%m))%m;
        }
    }
    return sol[n-1];
    }
};
