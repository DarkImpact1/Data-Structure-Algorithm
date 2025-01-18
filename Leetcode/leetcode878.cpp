/*
878. Nth Magical Number
A positive integer is magical if it is divisible by either a or b.
Given the three integers n, a, and b, return the nth magical number. Since the answer may be very large, return it modulo 109 + 7.

*/

    
int mod_add(int a, int b,int m){
    return ((a%m)+ (b%m))%m;
}
int two_pointer_approach(int n, int a, int b) {
    int m = 1e9+7;
    int curr = 1;
    int init_a = a;
    int init_b = b;
    int curr_magical_num = min(a,b);
    while(curr <= n){
        if(a<b){
            curr_magical_num = a;
            a = mod_add(a,init_a,m);
        }else if(b<a){
            curr_magical_num = b;
            b = mod_add(b,init_b,m);
        }else{
            curr_magical_num = a;
            a = mod_add(a,init_a,m);
            b = mod_add(b,init_b,m);
        }
        
        cout<<curr_magical_num<<" for curr "<<curr<<endl;
        curr++;
    }
    return curr_magical_num%m;
}


class Solution {
public:
    int m = 1e9 + 7;

    int cal_gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    long long lcm(int a, int b) {
        return (long long)a * b / cal_gcd(a, b);
    }

    int total_divisor(int a, int b, long long mid) {
        long long count_a = mid / a;
        long long count_b = mid / b;
        long long com_a_b = mid / lcm(a, b);
        return count_a + count_b - com_a_b;
    }

    int nthMagicalNumber(int n, int a, int b) {
        long long low = min(a, b);
        long long high = (long long)n * min(a, b);
        int result = 0;

        while (low <= high) {
            long long mid = (low + high) / 2;
            int total_till_mid = total_divisor(a, b, mid);

            if (total_till_mid < n) {
                low = mid + 1;
            } else {
                result = mid % m;
                high = mid - 1;
            }
        }

        return result;
    }
};
