// Decimal to binary conversion using Bit operation


#include <iostream>
#include<math.h>
using namespace std;

int main() {
  // variable n : number whome we want to convert to binary
    int n = 5;
  // variable i : basically the exponent of the 10, result : final result after conversion;
    int result = 0,i=0;
    while(n != 0){
      // a & b : gives the last bit of any number;
        int bit = n & 1;
        result = (bit * pow(10,i)) + result;
      // right shifting the bit by to shift the previous bit to the last position;
        n = n>>1;
        i++;
    }
    cout<<"Answer in Binary is "<<result<<endl;
    return 0;
}
