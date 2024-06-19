// problem : Factorial of N using recursion

#include <iostream>
using namespace std;
int factorial(int n){
    if( n < 1 ){
        return 1;
    }
    return  n * factorial(n-1);
}

int main() {
    cout<<"factorial of number using recursion\n";
    int n;
    cout<<"Enter the number ";
    cin>>n;
    cout<<factorial(n);
    return 0;
}