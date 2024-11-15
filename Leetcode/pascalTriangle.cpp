/*
leetcode 118
Given an integer numRows, return the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above 
*/

  int computeNcR(int row, int column) {
  if (column == 0 || column == row) return 1;  
  int result = 1;
  for (int i = 0; i < column; i++) {
      result = result * (row - i);
      result = result / (i + 1);
  }
  return result;
  }

  vector<vector<int>> generate(int numRows) {
      vector<vector<int>> answer;
      for (int row = 0; row < numRows; row++) { 
          vector<int> rowval;
          for (int col = 0; col <= row; col++) {  
              int val = computeNcR(row, col);
              rowval.push_back(val);
          }
          answer.push_back(rowval);
      }
      return answer;
  }
