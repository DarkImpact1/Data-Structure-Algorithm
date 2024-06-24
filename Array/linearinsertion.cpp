#include <bits/stdc++.h>
using namespace std;
// insert zero at given index 
void insert(int arr[], int pos, int n){
	for(int i = n-1; i >= pos; i--){
		arr[i] = arr[i-1];
	}
	arr[pos-1] = 0;
}
int main() {
    int arr[6] = {10,3,1,5,9};
    insert(arr,3,6);
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}