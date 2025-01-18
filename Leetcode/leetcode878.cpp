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
