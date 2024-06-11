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
    int n;
    cout<<"Enter value of N upto which you want to print series : ";
    cin >> n;
    print(n);
    return 0;
}