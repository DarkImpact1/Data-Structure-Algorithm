// Sum of N natural number using recursion 

// though it is not a optimised solution to calculate the sum of N natural number 
// but in order to learn recursion try it 

// Faster way to calculate the sum of N natural number is : directly use the formula
// int sum = (N*(N+1))/2

#include <iostream>
using namespace std;
int sum(int n){
    if( n < 1 ){
        return 0;
    }
    return  n + sum(n-1);
}

int main() {
    cout<<"Sum of N natural number using recursion\n";
    int n;
    cout<<"Enter the number ";
    cin>>n;
    cout<<sum(n);
    return 0;
}