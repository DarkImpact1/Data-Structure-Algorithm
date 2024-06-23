#include<bits/stdc++.h>
using namespace std;


int find_largest(int arr[], int n){
    int largest = INT_MIN;
    for(int i=0; i<n; i++){
        if(arr[i]> largest){
            largest = arr[i];
        }
    }
    return largest;
}

int find_sLargest(int arr[], int n){
    int largest = INT_MIN;
    int s_largest = INT_MIN;
    for(int i=0; i<n; i++){
        if(arr[i]> largest){
            s_largest = largest;
            largest = arr[i];
        }else if(arr[i]> s_largest && arr[i] < largest){
                s_largest = arr[i];
        }
    }
    return s_largest;
}

int main(){
    int arr[5]={1,2,3,4,5};
    cout<<"first Largest "<< find_largest(arr,5)<<endl;
    cout<<"Second Largest "<< find_sLargest(arr,5)<<endl;

}