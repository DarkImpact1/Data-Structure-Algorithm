#include<bits/stdc++.h>
using namespace std;

// better solution 
int find_missing(int arr[], int n){
    int sum= (n*(n+1))/2;
    int add=0;
    for(int i=0; i<n;i++){
        add+= arr[i];
    }
    return sum-add;
}
// Optimal Solution
/*
The reason it is optimal because it will now exceed the space n and in case of previous one 
since it is using n * n+1, it may exceed if n = 10**5 then we have to take another datatype "long"
*/
int find_missing2(int arr[], int n){
    int xor1 = 0;
    int xor2 = 0;
    for(int i=0;i<n;i++){
        xor1 = xor1 ^ (i+1);
        xor2 = xor2 ^ arr[i];
    }
    xor1 ^ n;
    return xor1 ^ xor2;
}
int main() {
    int arr[5]={1,2,4,5};
    cout<<"Missing number : "<<find_missing(arr,5)<<endl;
    cout<<"Missing number : "<<find_missing2(arr,5)<<endl;


    return 0;
}