// Problem 5 : print 1 ---> n using recursion without using + operator
// Backtracking problem
#include <iostream>
using namespace std;


void print(int i,int n){
    if(i < 1){
        return;
    }
    print(i-1,n);
    cout << i << endl;
}

int main() {
    cout<<"Problem 5 : print 1 ---> n using recursion without using + operator"<<endl;
    int n;
    cout<<"Enter value of N: ";
    cin >> n;
    print(n,n);
    return 0;
}