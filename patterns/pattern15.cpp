/*
Pattern :
                0 0 0 0 0 0 0 0 0 
                0 1 1 1 1 1 1 1 0 
                0 1 2 2 2 2 2 1 0 
                0 1 2 3 3 3 2 1 0 
                0 1 2 3 4 3 2 1 0 
                0 1 2 3 3 3 2 1 0 
                0 1 2 2 2 2 2 1 0 
                0 1 1 1 1 1 1 1 0 
                0 0 0 0 0 0 0 0 0 
            
*/

#include<bits/stdc++.h>
using namespace std;
void pattern(int n){
    for(int i=0;i<(2*n-1);i++){
        for(int j=0;j<(2*n-1);j++){
            int top = i, left = j;
            int right = (2*n -1)-1 -j;
            int bottom = (2*n -1)-1 -i;
            int short_dist = min(min(top,bottom),min(left,right));
            cout<<short_dist<<" ";
            }
        cout<<endl;
    }

}
int main(){
    cout<<"Pattern :"<<endl;
    pattern(5);
}