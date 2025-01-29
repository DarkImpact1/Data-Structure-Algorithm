/*
A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).

For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime. However, "3245" is not good because 3 is at an even index but is not even.
Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.

A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.
*/

/*
Approach 
since there are only 5 even digits and 4 prime digits so 
each even place will have 5 possible number to be places 
and each odd place will have 4 possible number to be places
therefor 
ans = 5^number_of_even_place * 4 ^ num_of_odd_places

I have used optimised way of calculating power which will take log n time 
  */
class Solution {
public:

    long long modMul(long long  a, long long b, int m){
        return (((a%m)*(b%m))%m);
    }
    
    // cal a^b
    long long calPow(long long a, long long  b, int m){
        if(b == 0){
            return 1;
        }
        long long half = calPow(a,b/2,m);
        long long ans = modMul(half, half, m);
        if(b%2 == 0){
            return ans;
        }
        return modMul(a,ans,m);
    }
    
    int countGoodNumbers(long long n){
        long long num_odd_places = n/2;
        long long num_even_places = n-num_odd_places;
        // even number 0,2,4,6,8 = 5
        // primce number 2,3,5,7 = 4
        int m = 1e9+7;
        long long ans1 = calPow(5,num_even_places,m);
        long long ans2 = calPow(4,num_odd_places,m);
        return modMul(ans1,ans2, m);
        
    }
};
