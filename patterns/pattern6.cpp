/*
pattern :
                    *
                   ***
                  *****
                 *******
                ********* 
*/

#include<bits/stdc++.h>
using namespace std;
void pattern(int n){
    for(int i=0;i<n;i++){
        //for space
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }
        // for *
        for(int j=0; j<2*i + 1;j++){
            cout<<"*";
        }
        // for space 
        for(int j=0; j<n-i-1;j++){
            cout<<" ";
        }
        cout<<endl;
    }

}
int main(){
    cout<<"Pattern :"<<endl;
    pattern(8);
}