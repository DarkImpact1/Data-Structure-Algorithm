/*
Pattern :
                5 5 5 5 5 5 5 5 5 
                5 4 4 4 4 4 4 4 5 
                5 4 3 3 3 3 3 4 5 
                5 4 3 2 2 2 3 4 5 
                5 4 3 2 1 2 3 4 5 
                5 4 3 2 2 2 3 4 5 
                5 4 3 3 3 3 3 4 5 
                5 4 4 4 4 4 4 4 5 
                5 5 5 5 5 5 5 5 5
            
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
            cout<<n -short_dist<<" ";
            }
        cout<<endl;
    }

}
int main(){
    cout<<"Pattern :"<<endl;
    pattern(5);
}