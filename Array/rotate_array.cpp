
#include <bits/stdc++.h>
using namespace std;
// left rotate arry by one place 
void rotate_one(int arr[], int n){
    int temp = arr[0];
    for(int i=1; i<n; i++){
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
}


// left rotate arry by d place 
void leftRotateByD(int arr[], int n, int d){
    
    d = d%n;
    int temp[d];
    // storing the value till d in temp arr
    for(int i=0; i<d;i++){
        temp[i] = arr[i];
    }
    // shifting the array by dth index to the left
    for(int i=d; i<n; i++){
        arr[i-d] = arr[i];
    }
    // filling the last remaining index from temp arr
    for(int i=n-d; i<n; i++ ){
        arr[i] = temp[i - (n-d)];
    }
}
int main() {
    int arr[5] = {1,2,3,4,5};
    // rotate_one(arr,5);
    leftRotateByD(arr,5,1);
    cout<<"left Rotated array by dth index "<<endl;
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}