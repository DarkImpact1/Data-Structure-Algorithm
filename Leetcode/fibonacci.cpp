#include<bits/stdc++.h>
using namespace std;

// Time complexity O(n) -- > takes 0ms to execute this code
int fib(int n) {
    if( n <=1 ){
        return n;
    }
    auto a = 0, b = 1;
    for(int i=2; i<=n; i++){
        int temp = a+b;
        a = b;
        b = temp;
        
        
    }
    return b;
}

int main(){
    cout<<"Fib(5) "<<fib(5)<<endl;
}