#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int string = "101";
    int result = 0;
    int i = 0;
/*
    while (n != 0) {
        int bit = n & 1;
        cout<<"bit : "<<bit << endl;
        result = ( bit * pow(2, i) ) + result;
        cout<<"result : "<<result<<endl;
        n = n / 10;
        cout<<"n : "<<n<<endl;
        i++;
    }
*/
    p2 = 2;
    for (int i=n.size()-1; i>=0; i--){
        int bit = n&1;
        if(n&1) res += p2 * i;
        p2 *= 2;

    cout << "Answer in Decimal is " << result << endl;
    return 0;
}

