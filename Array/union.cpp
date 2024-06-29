#include <bits/stdc++.h>
using namespace std;

// Problem find union of two sorted array 

vector<int> find_union(int arr1[], int n1, int arr2[], int n2){
    int i=0, j=0;
    vector<int> union_arr;
    while(i < n1 && j < n2){
        if(arr1[i] <= arr2[j]){
            if(union_arr.size() == 0 || union_arr.back() != arr1[i]){
                union_arr.push_back(arr1[i]);
            }
            i++;

        }else{
            if(union_arr.size() == 0 || union_arr.back() != arr2[j]){
                union_arr.push_back(arr2[j]);
            }
            j++;
        }

        
    }
    while(i < n1){
        if(union_arr.size() == 0 || union_arr.back() != arr1[i]){
                union_arr.push_back(arr1[i]);
            }
            i++;
    }
    while(j < n2){
        if(union_arr.size() == 0 || union_arr.back() != arr2[j]){
                union_arr.push_back(arr2[j]);
            }
            j++;
    }
    return union_arr;
}



int main() {
    int arr1[5] = {1,2,2,3,4};
    int arr2[5] = {1,3,4,5,6};
    for(auto it : find_union(arr1, 5, arr2, 5)){
        cout<<it <<" ";
    }
    return 0;
}