/*
Pattern :
            ABCDE
            ABCD
            ABC
            AB
            A
            
*/

#include<bits/stdc++.h>
using namespace std;
void pattern(int n){
    for(int i=0;i<n;i++){
        int num = 65;
        for(int j=0;j<(n-i);j++){
            cout<<char(num);
            num++;
            }
        cout<<endl;
    }

}
int main(){
    cout<<"Pattern :"<<endl;
    pattern(5);
}