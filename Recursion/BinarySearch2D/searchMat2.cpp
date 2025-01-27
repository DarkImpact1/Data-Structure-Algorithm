/*
240. Search a 2D Matrix II
Solved
Medium
Topics
Companies
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
 
*/

class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int nR = matrix.size(), nC = matrix[0].size();
        int row = 0, col = nC-1;
        while(row < nR && col >=0){
            if(matrix[row][col] == target) return true;
            if(matrix[row][col] > target) col--;
            else row++;
        }
        return false;
    }
};
