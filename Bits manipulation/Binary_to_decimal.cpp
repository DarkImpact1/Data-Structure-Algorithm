#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n = 101;
    int result = 0;
    int i = 0;
    while (n != 0) {
        int bit = n & 1;
        cout<<"bit : "<<bit << endl;
        result = ( bit * pow(2, i) ) + result;
        cout<<"result : "<<result<<endl;
        n = n / 10;
        cout<<"n : "<<n<<endl;
        i++;
    }

    for (int i=0; i<n; i++){
        int bit = n&1;
        if(n&1) res += p2 * i;
        p2 *= 2;

    cout << "Answer in Decimal is " << result << endl;
    return 0;
}
