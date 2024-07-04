#include<bits/stdc++.h>
using namespace std;
/*
         1
      1     1
   1     2     2
 1    3     3    1
 

*/
// 1.st problem : given row and column find the element
/*
  r-1 
     C
      c-1
*/

int find_ele_pascal(int r, int c){
    int ans = 1;
    int r = r - 1;
    int c = c - 1;
    for(int i = 1 ; i <=c; i++){
            ans = ans*(r/i);
            r--;
    }
    return ans;
}





int main(){

}