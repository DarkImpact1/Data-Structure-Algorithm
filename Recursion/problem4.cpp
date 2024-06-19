// Problem : print 1---> N using recursion 
#include <iostream>
using namespace std;

void print(int i,int n){
    if(i > n){
        return;
    }
    cout << i++ << endl;
    print(i,n);
}

int main() {
    cout<<"Problem : print 1---> N using recursion "<<endl;
    int n;
    cout<<"Enter value of N : ";
    cin >> n;
    print(1,n);
    return 0;
}