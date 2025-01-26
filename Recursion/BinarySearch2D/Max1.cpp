/*
You are given a 2D binary array arr[][] consisting of only 1s and 0s. Each row of the array is sorted in non-decreasing order. Your task is to find and return the index of the first row that contains the maximum number of 1s. If no such row exists, return -1.

Note:

The array follows 0-based indexing.
The number of rows and columns in the array are denoted by n and m respectively.
Examples:

Input: arr[][] = [[0,1,1,1], [0,0,1,1], [1,1,1,1], [0,0,0,0]]
Output: 2
Explanation: Row 2 contains the most number of 1s (4 1s). Hence, the output is 2.
Input: arr[][] = [[0,0], [1,1]]
Output: 1
Explanation: Row 1 contains the most number of 1s (2 1s). Hence, the output is 1.
*/

// User function template for C++
class Solution {
  public:
    int numOne(vector<int> & arr, int col){
        
        // [1,1,1,1,1,1]
        if(arr[0] == 1) return col ;
        // [0,0,0,0,0,0]
        if(arr[col - 1] == 0) return 0;
        // []
        int low = 0, high = col;
        while(low <= high){
            int mid = (low+high)/2;
            if(arr[mid] == 1) high = mid-1;
            else low = mid+1;
        }
        return col - low;
    }
    int rowWithMax1s(vector<vector<int>> &arr) {
        int r = arr.size(), col = arr[0].size();
        int maxiRow = -1, maxNum =0;
        for(int i = 0; i<r; i++){
            
            int num1 = numOne(arr[i],col);
            if(num1 > maxNum){
                maxNum = num1;
                maxiRow = i;
            }
        }
        
        return maxiRow;
    }
};
