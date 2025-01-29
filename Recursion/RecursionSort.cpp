// Sorting using recurstion 


#include <bits/stdc++.h>
using namespace std;

void print(vector<int> arr){
    cout<<"{";
    for(auto it : arr){
        cout<<it<<" ";
    }
    cout<<"}"<<endl;
}
void Insert(vector<int>& arr, int temp) {
    // Base case: if the array is empty or the last element is <= temp, push temp
    cout<<"Inserting "<<temp<<" in ";
    print(arr);
    if (arr.size() == 0 || arr[arr.size() - 1] <= temp) {
        cout<<"inserted "<<temp<<" in arr ";print(arr);
        arr.push_back(temp);
        return;
    }
    
    // Remove the last element and recursively insert temp
    int val = arr[arr.size() - 1];
    cout<<"removed "<<val<<" from sorted arr "<<endl;
    arr.pop_back();
    Insert(arr, temp);
    
    // Push back the removed element
    cout<<"Pushing "<<val<<" in arr "<<endl;
    arr.push_back(val);
}

void recursionSort(vector<int>& arr) {
    // Base case: if the array is empty, return
    if (arr.size() == 0) return;
    
    // Remove the last element and sort the remaining array
    int temp = arr[arr.size() - 1];
    cout<<"removing "<<temp<<" from ";
    print(arr);
    arr.pop_back();
    recursionSort(arr);
    
    // Insert the removed element in the sorted array
    Insert(arr, temp);
}

int main() {
    vector<int> ar = {3, 2, 4};
    recursionSort(ar);
    cout<<"Sorted arr : ";
    for (auto el : ar) {
        cout << el << " ";
    }
    
    return 0;
}
