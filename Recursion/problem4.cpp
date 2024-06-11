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
    print(1,10);
    return 0;
}