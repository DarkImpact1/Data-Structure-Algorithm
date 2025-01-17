/*
Geeks for Geeks : 
Index of an Extra Element
You have given two sorted arrays arr1[] & arr2[] of distinct elements. 
The first array has one element extra added in between. Return the index of the extra element.

Note: 0-based indexing is followed.
*/

int findExtra(vector<int>& a, vector<int>& b) {
    if(a[a.size()-1])!=b[b.size()-1]) return a.size()-1;
    // O(n)
    for(int i=0; i<b.size(); i++){
        if(a[i]!= b[i])return i;
    }
    // O (log n)
    int left = 0, right = a.size()-1;
    while(left <= right){
        int mid = ( left + right)/2;
        if(a[mid] == b[mid]){
            left = mid + 1;
        }else{
            if(mid == 0 || a[mid-1] == b[mid - 1]) return mid;
            right = mid -1;
        }
        
    }
    
}
