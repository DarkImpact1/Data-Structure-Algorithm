#include<bits/stdc++.h>
using namespace std;
/* 

this is the problem statement
         1
      1     1
   1     2     1
 1    3     3    1
 

*/
// 1.st problem : given row and column find the element
/*
  r-1 
     C
      c-1
*/

long long find_ele_pascal(int r, int c){
    long long ans = 1; 
    r = r - 1;
    c = c - 1;
    for(int i = 1 ; i <=c; i++){
            ans = r*(ans/i);
            r--;
    }
    return ans;
}

// second problem : find nth row given n
/*
    nth row have n element */

vector<int> find_nth_row(int r){
    vector<int> res;
    int ans = 1;
    int num = r-1;
    for(int col=0; col< r; col++){
        if(col == 0){
            res.push_back(ans);
        }else{
            ans = ans*num;
            ans = ans/col;
            num--;
            res.push_back(ans);
        }
    }
    return res;
}
// Given an integer numRows, return the first numRows of Pascal's triangle.

vector<vector<int>> generate(int numRows){
    vector<vector<int>> series;
    for(int i=1; i<=numRows; i++){
        series.push_back(find_nth_row(i));
    }
    return series;
    
}
int main(){
    // cout<<find_ele_pascal(3,3)<<endl;
    // for(auto ele : find_nth_row(4)){
    //     cout<<ele<<" ";
    // }
    
    vector<vector<int>> traingle = generate(6);
    for(auto row : traingle){
        for(auto ele : row){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}
