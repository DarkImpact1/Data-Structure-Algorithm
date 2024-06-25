#include<bits/stdc++.h>
using namespace std;

// Find maximum consecutve ones
int find_max_ones(int arr[], int n){
    int max = 0,count=0;
    for(int i=0; i<n; i++){
        if(arr[i]==1){
            count++;
            if(max < count){
                max = count;
            }
        }else{
            count = 0;
        }
    }
    return max;
}

int main() {
    int arr[5]={1,2,4,5}; 
    int arr2[10] = {1,1,1,0,1,1,1,1,1,0};
    cout<<"Max 1s are : "<< find_max_ones(arr2,10);


    return 0;
}