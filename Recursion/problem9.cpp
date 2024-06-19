// Problem : Reverse the array using Recursion 


#include <iostream>
using namespace std;

void reverse(int start, int end, int arr[]){
    if(start >= end){
        return ;
    }
    int n = arr[start];
    arr[start] = arr[end];
    arr[end] = n;
    reverse(start+1, end-1,arr);
}

int main() {
    int arr[] = {5, 4, 3, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Reverse the array using recursion" << endl;
    reverse(0, size - 1, arr);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}