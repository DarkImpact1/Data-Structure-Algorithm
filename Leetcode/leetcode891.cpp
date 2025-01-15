/*  891. Sum of Subsequence Widths
The width of a sequence is the difference between the maximum and minimum elements in the sequence.
Given an array of integers nums, return the sum of the widths of all the non-empty subsequences of nums. Since the
answer may be very large, return it modulo 109 + 7.
A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the
order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].
  */


/*
Contibution technique of a[i] and number of of subsequence between i and j
so number of element between i and j suppose 5 therefor number of subsequence 2^5 but remove 1 because width will be zero [2] 2-2 = 0
now positive contribution will me when it is max and it will be (2^i)-1
and negative contribution will be when it is minimum it will be (2^n-i-1)-1
and width will be width = width + positive contribution  - negative contribution

  */
class Solution {
public:
    int modAdd(int x, int y, int m){
        return ((x%m)+(y%m))%m;
    }
    int modSub(int x, int y, int m){
        int res = (x%m)-(y%m);
        if(res < 0){
            res += m;
        }
        return res %m;
    }

    int modMul(long x, long y, int m){
        return ((x%m)*(y%m))%m;
    }

    int sumSubseqWidths(vector<int>& nums) {
        int n = nums.size();
        long modulus = 1000000007;
        int power_2[n];
        sort(nums.begin(), nums.end());
        int curr_pow_2_i = 1; //2
        // here we are calculating and storing "2^i -1"
        for(int i=0;i<n;i++){
            power_2[i] = modSub(curr_pow_2_i,1,modulus);
            curr_pow_2_i = modMul(curr_pow_2_i,2,modulus);
        }
        int sum_width = 0;
        for(int i=0; i<n; i++){
            sum_width = modAdd(sum_width, modMul(nums[i], power_2[i], modulus), modulus);
            sum_width = modSub(sum_width, modMul(nums[i], power_2[n-i-1], modulus), modulus);
        }
    
        return sum_width;
    }
};
