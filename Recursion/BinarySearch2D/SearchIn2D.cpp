/*
Medium
Topics
Companies
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.
*/

class Solution {
public:
    bool find(vector<int> & arr, int target){
        int low = 0, high = arr.size();
        while(low <= high){
            int mid = (low+high)/2;
            if(arr[mid] == target) return true;
            if(arr[mid] > target) high = mid-1;
            else low = mid+1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int nRow = matrix.size(),lastEl = matrix[0].size()-1;
        int curRow = 0;
        while(curRow < nRow){
            if(matrix[curRow][lastEl] >= target){
                return find(matrix[curRow], target);
            }
            curRow++;
        }
        return false;
    }
};
