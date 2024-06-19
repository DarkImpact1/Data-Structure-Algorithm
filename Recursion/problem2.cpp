// Problem : Print N ---- > 1 using recursion

#include <iostream>
using namespace std;


void print(int n){
    if(n < 1){
        return;
    }
    cout << n-- << endl;
    print(n);
}

int main() {
    cout<<"Print N ---- > 1 using recursion"<<endl;
    int n;
    cout<<"Enter value of N: ";
    cin >> n;
    print(n);
    return 0;
}