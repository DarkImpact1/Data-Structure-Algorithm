// Problem: Fibonacci number using recursion 
// multiple recursion call
#include <iostream>
using namespace std;
int fib(int n){
    if( n<= 1){
        return n;
    }
    int first = fib(n-1);
    int second = fib(n-2);
    return  first + second;
}

int main() {
    cout<<"Fibonacci number using recursion\n";
    int n;
    cout<<"Enter the position (n) of the Fibonacci sequence:  ";
    cin>>n;
    cout<<fib(n);
    return 0;
}
