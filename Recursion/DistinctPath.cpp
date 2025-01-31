// given a row x col grid if a user can move either downward or either rightward count the number of distinct path that is available
// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int countDistinctPath(int row, int col, int i, int j){
    if(i== row-1 && j == col-1){
        return 1;
    }
    if(i == row-1){
        return countDistinctPath(row, col, i, j+1);
    }
    if(j == col-1){
        return countDistinctPath(row, col, i+1, j);
    }
    if(i < row && j < col){
        return countDistinctPath(row, col, i+1, j)+ countDistinctPath(row, col, i, j+1);
    }
    return 0;
}

// optimised one
void optimisedCount(int row, int col, int i, int j, int& count){
    // if you are the last row or last col simply increase the count becuase there will be only one path 
    if( i == row -1 || j == col-1){
        count++;
        return;
    }
    optimisedCount(row, col, i+1, j, count);
    optimisedCount(row, col, i, j+1, count);
}
int main() {
    cout<<countDistinctPath(3,3,0,0)<<endl;
    int count = 0;
    optimisedCount(3,3,0,0,count);
    cout<<count<<endl;
    return 0;
}
