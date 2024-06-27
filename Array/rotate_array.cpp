
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
// simplest method 
void rotate(int arr[], int n, int d){
    //[1,2,3,4,5]
    // d = 3
    reverse(arr,arr+d); // [3,2,1]
    reverse(arr+d,arr+n); // [5,4]
    reverse(arr,arr+n);//[4,5,1,2,3]
}
int main() {
    int arr[5] = {1,2,3,4,5};
    int d=3;
    rotate(arr,5,d);
    cout<<"left Rotated array by "<<d<<"th index "<<endl;
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}