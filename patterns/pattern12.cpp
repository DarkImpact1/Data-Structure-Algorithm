/*
Pattern :
                1
                2 3
                4 5 6
                7 8 9 10
                11 12 13 14 15 
*/

#include<bits/stdc++.h>
using namespace std;
void pattern(int n){
    int num = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<num<<" ";
            num++;
            }
        cout<<endl;
    }

}
int main(){
    cout<<"Pattern :"<<endl;
    pattern(5);
}