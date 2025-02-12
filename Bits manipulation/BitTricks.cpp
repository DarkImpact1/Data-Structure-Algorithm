// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;


void swap(){
    int a = 5, b = 6;
    cout<<"before swap : a = "<<a <<" | b = "<<b<<endl;
    a = a^b; 
    b = a^b;
    a = a^b;
    cout<<"after swap : a = "<<a <<" | b = "<<b<<endl;
}

void isSetBit(){
    int n = 13; // 1101;
    int i = 2; // it is set
    
    // 1<<2 = 100
    // 1101
    //& 100 will will give 100 
    cout<<"Using left shift operator "<<endl;
    if(n&(1<<i) != 0){
        cout<<i<<"th bit of "<<n<<" is set"<<endl;
    }else{
        cout<<i<<"th bit of "<<n<<" is not set"<<endl;
    }
    // 13 = 1101 
    // after right shift by 2 it will become 11
    //  11
    // & 1 will result 1 
    
    cout<<"Using right shift operator "<<endl;
    n = n>>i;
    if(n&1 == 1){
        cout<<i<<"th bit of "<<n<<" is set"<<endl;
    }else{
        cout<<i<<"th bit of "<<n<<" is not set"<<endl;
    }
}

void setIthBit(){
    int n = 13; // 1101
    int i = 1; 
    cout<<"value of n before setting "<<i<<"th bit is "<<n<<endl;

    // after setting 1st bit 13 it should become 1111 that is 15
    n = n | 1<<i;
    cout<<"value of n after setting "<<i<<"th bit is "<<n<<endl;
}

void clearIthBit(){
    int n = 15; // 1111;
    int i = 2;// 1011; 11
    cout<<"value of n before clearing "<<i<<"th bit is "<<n<<endl;
    
    n = n & ~(1<<i);
    cout<<"value of n after clearing "<<i<<"th bit is "<<n<<endl;
    
    
}
int main() {
    swap();
    isSetBit();
    setIthBit();
    clearIthBit();
}
