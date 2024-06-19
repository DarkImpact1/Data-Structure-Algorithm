// Problem : Print N ----> 1 using recursion but without using Negative sign 
// This problem is basically a backtracking problem
#include <iostream>
using namespace std;
void print(int i, int n){
    if(i>n){
        return ;
    }
    print(i+1,n);
    // printing after recursive call 
    cout<<i<<endl;
}

int main() {
    cout<<"Print N ----> 1 using recursion but without using Negative sign "<<endl;
    int n;
    cout<<"Enter value of N: ";
    cin >> n;
    print(1,n);
    return 0;
}