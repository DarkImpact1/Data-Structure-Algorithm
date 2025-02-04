/*
A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.

Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].

You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.

 
*/
/*
here's the intuition 
firstly find the mid col 
then find max ele of that col
then check whether it is peak in that row 
if it is smaller than left then move toward right 
else move toward left
*/
class Solution {
public:
    int findMaxRow(vector<vector<int>>&matrix, int numRow, int col){
        int maxi = INT_MIN, indexMaxi = 0;
        for(int i=0; i<numRow; i++){
            if(matrix[i][col] > maxi){
                maxi = matrix[i][col];
                indexMaxi = i;
            }
        }
        return indexMaxi;
    }


    vector<int> findPeakGrid(vector<vector<int>>& matrix) {
        int numRow = matrix.size(), numCol = matrix[0].size();
        int low = 0, high = numCol-1;
        while(low <= high){
            int colnum = (low+high)/2;
            int maxRow = findMaxRow(matrix, numRow, colnum);
            int leftEle = colnum-1 >= 0 ? matrix[maxRow][colnum -1] :-1;
            int rightEl = colnum+1 < numCol ? matrix[maxRow][colnum+1]:-1;
            // lets check whether it's peak or not
            int ele = matrix[maxRow][colnum];
            // cout<<"leftEle "<<leftEle<<" ele "<<ele<<" rightEle "<<rightEl<<endl;
            if(ele > leftEle && ele > rightEl) return {maxRow,colnum};
            // if left element  > left then peak is at the left side
            if(leftEle > ele) high = colnum - 1;
            // else peak is at the right side
            else low = colnum+1;
        
        }
        return {-1,-1};
    }
};
