/*

Pattern :
            1        1
            22      22
            333    333
            4444  4444
            5555555555
*/

#include<bits/stdc++.h>
using namespace std;
void pattern(int n){
    int start;
    for(int i=1;i<=n;i++){
        // number
        for(int j=1; j<=i; j++){
            cout<<i;
        }
        // space
        for(int j=0; j <2*(n-i+1) -2; j++){
            cout<<" ";
        }
        // number
        for(int j=1; j<=i; j++){
            cout<<i;
        }
        cout<<endl;
    }

}
int main(){
    cout<<"Pattern :"<<endl;
    pattern(5);
}