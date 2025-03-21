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
    //(1<<2) -> 100 and ~100 -> 011 
    //  1111
    // &1011 -> 1011 i.e 11
    cout<<"value of n after clearing "<<i<<"th bit is "<<n<<endl;

}
void toggleIthBit(){
    int n = 15, i = 2;
    cout<<"before toggeling "<<i<<" bit n= "<<n<<endl;
    n = n^(1<<i);
    //  1111 
    // ^0100 -> 1011 ->13;
    cout<<"after toggeling "<<i<<" bit n= "<<n<<endl;
    
    n = n^(1<<i);
    
    cout<<"after toggeling "<<i<<" bit again n= "<<n<<endl;
}

void removeLastBit(){
    int n = 12;
    cout<<"value of n before removing last bit "<<n<<endl;
    n = n&(n-1);
    // 12 =  1100 ; 11 = 1011
    //    1100
    //   &1011
    // =  1000 = 8
    cout<<"value of n after removing last bit "<<n<<endl;
}

void isPowerOfTwo(){
    int n = 16;
    //  10000  -> 16
    //  01111  -> 15
    // &00000 -> 0
    if((n&(n-1)) == 0){
        cout<<"it is power of 2 "<<endl;
    }else{
        cout<<"it is not power of 2"<<endl;
    }
}

void countSetBit(){
    int n = 15; // 1111 ans-> 4;
    int x = n;
    int cnt = 0;
    // simple division approach O(log2 n)
    while(n>1){
        if(n%2 == 1) cnt+=1;
        n = n/2;
    }
    // at last either n will be 0 or n will be 1 
    cout<<"number of set bit in "<<x <<" is "<<(cnt+n)<<endl;
    
    // here is the bit apporach 
    n = x;
    int c = 0;
    while(n>1){
        
        if(n&1) c+=1;
        n = n>>1;
    }
    cout<<"number of set bit in "<<x<<" is "<<(c+n)<<endl;
    
    
    // another approach of setting last bit as 0 O(no set bit)
    n = 13;
    x = n;
    c = 0;
    while(n!=0){
        c+=1;
        n = n&n-1;
    }
    cout<<"number of set bit in "<<x<<" is "<<(c+n)<<endl;

    
    

    
}
int main() {

    countSetBit();
}
