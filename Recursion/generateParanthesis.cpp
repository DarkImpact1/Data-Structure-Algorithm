// generate all possible parathesis 

/*
approach 

we can only insert close bracket iff number of close > number of open and we can insert open till open bracket is exhausted
and base case will be
when num open == 0 and num close ==0 
*/

class Solution {
public:
    void solve(int open, int close, string temp, vector<string>&output){
        if(open==0 && close == 0){
            output.push_back(temp);
        }
        if(open != 0){
            solve(open-1, close, temp+'(', output);
        }
        if(close > open){
            solve(open, close-1, temp +')', output);
        }
    }
    vector<string> generateParenthesis(int n) {
        string temp;
        vector<string> answer;
        solve(n,n,temp,answer);
        return answer;
    }
};
