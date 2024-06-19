// Check whether string is palindrome or not using recursion 
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int i, string &str){
    if(i >= str.size()/2) return true;
    if(str[i] != str[str.size() - i - 1]) return false;
    return isPalindrome(i+1,str);
}

int main() {
    cout<<"Check whether string is Palindrome or not using Recursion "<<endl;
    string str;
    cout<<"Enter the string : ";
    cin>>str;
    if(isPalindrome(0,str)) cout<<"It is palindrome "<<endl;
    else cout<<"Not a palindrome"<<endl;
    return 0;
}