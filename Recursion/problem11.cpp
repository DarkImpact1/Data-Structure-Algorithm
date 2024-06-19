// Printing all subsequence of array using recursion 

#include <bits/stdc++.h>
using namespace std;

void printSubsequence(int i, vector<int> &ds, int arr[], int n){
    if(i >= n){
        cout<<"{";
        for(auto element : ds){
            cout<< element <<" ";
        }
        cout<<"}"<<endl;
        return;
    }
    // taking element into subsequence then orinting subsequence 
    ds.push_back(arr[i]);
    printSubsequence(i+1,ds,arr,n);
    ds.pop_back();
    // removing element from subsequence and then printing subsequence
    printSubsequence(i+1,ds,arr,n);
}

int main() {
    cout<<"Printing all subsequence of array using recursion "<<endl;
    int arr[] = {1,2,3};
    int n = 3;
    vector<int> ds;
    printSubsequence(0,ds,arr,n);
    return 0;
}