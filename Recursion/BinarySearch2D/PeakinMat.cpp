/*

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
            // if leftelement  < ele then peak is at right side
          
            if(leftEle < ele) low = colnum + 1;
            // if element > left then peak is at left
            else high = colnum-1;
        
        }
        return {-1,-1};
    }
};
