/*
17. Letter Combinations of a Phone Number

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
*/


// here's the approach take one digit and add all its corresponding value to temp and repeat till you reach at the end of digit

class Solution {
public:
    void findNGen(string& digits, string temp, vector<string>& result, int ind, string letters[]){
        if(ind == digits.size()){
            result.push_back(temp);
            return;
        }
        int num = digits[ind] - '0';
        string mapped_value = letters[num];
        for(int i =0; i<mapped_value.size(); i++){
            temp.push_back(mapped_value[i]);
            findNGen(digits, temp, result,ind+1,letters);
            temp.pop_back();
        }
        return;
    }

    vector<string> letterCombinations(string digits) {
        vector<string> answer;
        if(digits.size() == 0) return answer;
        string letters[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string temp;
        findNGen(digits,temp,answer,0,letters);
        return answer;
        
    }
};
