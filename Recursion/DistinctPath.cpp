// given a row x col grid if a user can move either downward or either rightward count the number of distinct path that is available


// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int countDistinctPath(int row, int col, int i, int j){
  // if reaches the end return 1
    if(i== row-1 && j == col-1){
        return 1;
    }
    // if user is at the very bottm of grid then he can only move rightward 
    if(i == row-1){
        return countDistinctPath(row, col, i, j+1);
    }
  // if user is at the right corner then he can only move downward only
    if(j == col-1){
        return countDistinctPath(row, col, i+1, j);
    }
  // if user is somewhere between then he can either move downward or rightward
    if(i < row && j < col){
        return countDistinctPath(row, col, i+1, j)+ countDistinctPath(row, col, i, j+1);
    }
  // else return 0
    return 0;
}
int main() {
    cout<<countDistinctPath(3,3,1,1);
    return 0;
}
