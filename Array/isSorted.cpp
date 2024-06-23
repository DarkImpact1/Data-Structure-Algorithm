#include<bits/stdc++.h>
using namespace std;

bool isSorted(int arr[], int n){
    for(int i=1; i<n; i++){
        if(arr[i] < arr[i-1]){
            return false;
        }
    }
    return true;
}
int main(){
    int arr[5]={1,2,3,4,5};
    cout<<"Is sorted "<< isSorted(arr,5)<<endl;
}