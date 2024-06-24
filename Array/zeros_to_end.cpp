#include <bits/stdc++.h>
using namespace std;

// Problem move all zeros to end

// brute force methos 
void brute_shift(int arr[], int n){
    vector<int> temp;
    // storing all the non zero element in temp arr
    for(int i=0; i<n; i++){
        if(arr[i] != 0){
            temp.push_back(arr[i]);
        }
    }
    for(int i=0; i<n; i++){
        if(i<temp.size()){
            arr[i] = temp[i];
        }else{
            arr[i] = 0;
        }
    }
}
// better solution using two pointer appraoch
void better_shift(int arr[], int n){
    int i=0, j=0;
    while(j < n){
        if(arr[j]!=0){
            swap(arr[i], arr[j]);
            i++;
        }
        j++;
    }
}
int main() {
    int arr[5] = {10,3,0,5,9};
    brute_shift(arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}