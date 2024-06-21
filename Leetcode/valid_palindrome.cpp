#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
        string out;
        for(char c : s){
            if(isalnum(c)){ 
                out+=tolower(c);
            }
        }
        int start = 0, end = out.size()-1;
        while(start <= end){
            if(out[start++] != out[end--]) return false;
        }
        return true; 
}
int main(){
    string s = "A man, a plan, a canal: Panama";
    cout<<isPalindrome(s)<<endl;
}