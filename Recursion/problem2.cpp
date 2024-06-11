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
    print(10);
    return 0;
}