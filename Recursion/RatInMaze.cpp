/*
Rat in a Maze Problem - I

Consider a rat placed at position (0, 0) in an n x n square matrix mat. The rat's goal is to reach the destination at position (n-1, n-1). The rat can move in four possible directions: 'U'(up), 'D'(down), 'L' (left), 'R' (right).

The matrix contains only two possible values:

0: A blocked cell through which the rat cannot travel.
1: A free cell that the rat can pass through.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell. In case of no path, return an empty list.+

The task is to find all possible paths the rat can take to reach the destination, starting from (0, 0) and ending at (n-1, n-1), under the condition that the rat cannot revisit any cell along the same path. Furthermore, the rat can only move to adjacent cells that are within the bounds of the matrix and not blocked.

Return the final result vector in lexicographically smallest order.

Examples:

Input: mat[][] = [[1, 0, 0, 0], [1, 1, 0, 1], [1, 1, 0, 0], [0, 1, 1, 1]]
Output: ["DDRDRR", "DRDDRR"]
Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.

*/


// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

void makeMove(vector<vector<int>> &maze,int row, int col, int i, int j, vector<string>& ans, string temp, vector<vector<int>> & visited){
    if(i == row-1 && j== col-1){
        ans.push_back(temp);
        return;
    }
    
    
    visited[i][j] = 1; // mark as visited

    // making downward move
    if(i+1 < row && !visited[i+1][j] && maze[i+1][j]==1){
        makeMove(maze,row,col,i+1, j, ans, temp+'D',visited);
    }
    // making left move 
    if(j-1>=0 && !visited[i][j-1] && maze[i][j-1]==1){
        makeMove(maze, row, col, i, j-1, ans, temp+'L', visited);
        
    }
    
    // making right move
    if(j+1 < col && !visited[i][j+1] && maze[i][j+1]== 1){
        makeMove(maze, row, col, i, j+1, ans, temp + 'R', visited);
    }
    // making upward move
    if(i-1 >= 0 &&  !visited[i-1][j] && maze[i-1][j] ==1){
        makeMove(maze, row, col,i-1, j, ans, temp+'U', visited);
    }
    
    visited[i][j] = 0;
}

vector<string> findPath(vector<vector<int>> &mat) {
        int n = mat.size();
        vector<vector<int>> visited(n, vector<int>(n,0));
        string temp;
        vector<string> result;
        if(mat[0][0] == 1)
            makeMove(mat,n,n, 0,0,result,temp, visited);
        return result;
        
    }


// less number of lines of code

void makeMove(vector<vector<int>> &maze, int row, int col, int i, int j, vector<string>& ans, string temp, vector<vector<int>> &visited, vector<vector<int>>& direction) {
    if (i == row - 1 && j == col - 1) {
        ans.push_back(temp);
        return;
    }

    string dirs = "DLRU";
    for (int k = 0; k < 4; k++) {  // Fixed loop condition
        int next_i = i + direction[k][0];  
        int next_j = j + direction[k][1]; 

        if (next_i >= 0 && next_i < row &&  // next i in range
            next_j >= 0 && next_j < col &&  // next j in range
            !visited[next_i][next_j] &&     // is not visited
            maze[next_i][next_j] == 1) {    // path available

            visited[i][j] = 1;  // Mark position where you are standing as visited
            makeMove(maze, row, col, next_i, next_j, ans, temp + dirs[k], visited, direction);
            visited[i][j] = 0;  // Mark as unvisited while backtracking
        }
    }
}

vector<string> findPath(vector<vector<int>> &mat) {
    int n = mat.size();
    vector<vector<int>> visited(n, vector<int>(n, 0));
    vector<vector<int>> direction{
        {1, 0},  // Down move
        {0, -1}, // Left move
        {0, 1},  // Right move
        {-1, 0}  // Up move
    };
    string temp;
    vector<string> result;
    if (mat[0][0] == 1)
        makeMove(mat, n, n, 0, 0, result, temp, visited, direction);
    return result;
}


int main() {
    vector<vector<int>> maze{
        {1,0,0,0},
        {1,1,0,1},
        {1,1,0,0},
        {0,1,1,1}
    };
   for(auto path : findPath(maze)){
       cout<<path<<" ";
   }
   cout<<endl;

    return 0;
}
