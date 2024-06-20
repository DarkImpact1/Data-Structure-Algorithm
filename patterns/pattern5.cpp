/*
pattern 2:
                1
                22
                333
                4444
                55555
*/

#include<bits/stdc++.h>
using namespace std;
void pattern(int n){
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            cout<<i;
        }
        cout<<endl;
    }

}
int main(){
    cout<<"Pattern 2 :"<<endl;
    pattern(5);
}