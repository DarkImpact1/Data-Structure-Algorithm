#include<bits/stdc++.h>
using namespace std;

// find the number that is appearing once 


// brute force method O(n2)
int brute_find_once(int arr[], int n){
    for(int i=0; i<n; i++){
        int num = arr[i];
        int count=0;
        for(int j=0; j<n;j++){
            if(arr[i] == arr[j]){
                count++;
            }
        }
        if(count == 1){
            return arr[i];
        }
    }
    return -1;
}
// better solution using hash
int better_find_once(int arr[], int n){
    int max_value = arr[0];
    for (int i = 1; i < n; i++) {
        if (max_value < arr[i]) {
            max_value = arr[i];
        }
    }
    int hash[max_value +1] = {0};
    for(int i=0; i<n; i++){
        hash[arr[i]]++;
    }
    for(int i=0; i<n; i++){
        if(hash[arr[i]]== 1){
            return arr[i];
        }
    }
    return -1;
    
}

// optimal way to find is x^x = 0
int optimal_find_once(int arr[], int n){
    int x = arr[0];
    for(int i=1; i<n;i++){
        x = x^arr[i];
    }
    return x;
}
int main() {
    int arr2[9] = {1,1,2,3,3,4,4,5,5};
    cout<<better_find_once(arr2,9);
    return 0;
}