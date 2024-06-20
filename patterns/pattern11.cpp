/*

Pattern :
            1        1
            12      12
            123    123
            1234  1234
            1234512345
*/

#include<bits/stdc++.h>
using namespace std;
void pattern(int n){
    int start;
    for(int i=1;i<=n;i++){
        // number
        for(int j=1; j<=i; j++){
            cout<<j;
        }
        // space
        for(int j=0; j <2*(n-i+1) -2; j++){
            cout<<" ";
        }
        // number
        for(int j=1; j<=i; j++){
            cout<<j;
        }
        cout<<endl;
    }

}
int main(){
    cout<<"Pattern :"<<endl;
    pattern(5);
}