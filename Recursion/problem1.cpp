/*
Problem : you have to print name "n" time using recursion 
*/

#include<iostream>
using namespace std;

void print(int n, string name){
    if(n < 1){
        return;
    }
    cout<<name<<endl;
    print(--n,name);
}
int main(){
    print(10,"Hello world");
}