#include <bits/stdc++.h>
using namespace std;

// finding intersection of two sorted array 
vector<int> find_intersection(int arr1[], int n1, int arr2[], int n2){
    vector<int> intersection;
    int i=0, j=0;
    while(i< n1 && j <n2){
        if(arr1[i] > arr2[j]){
            j++;
        }else if(arr1[i] < arr2[j]){
            i++;
        }else{
            intersection.push_back(arr1[i]);
            i++;
            j++;
        }
    } 
    return intersection;
}
int main() {
    int arr1[5] = {1,2,2,3,4};
    int arr2[5] = {1,3,4,5,6};
    for(auto it : find_intersection(arr1, 5, arr2, 5)){
        cout<<it <<" ";
    }
    return 0;
}