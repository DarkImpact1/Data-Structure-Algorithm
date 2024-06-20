/*
pattern :
                    11111
                    2222
                    333
                    44
                    5           
*/

#include<bits/stdc++.h>
using namespace std;

void pattern(int n){
    for(int i=1;i<=n;i++){
        for(int j=0;j<n-i+1;j++){
            cout<<i;
        }
        cout<<endl;
    }

}
int main(){
    cout<<"Pattern  :"<<endl;
    pattern(5);
}