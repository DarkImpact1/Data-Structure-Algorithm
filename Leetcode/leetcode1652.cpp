/*
1652. Defuse the Bomb
You have a bomb to defuse, and your time is running out! Your informer will provide you with a circular array code of length of n and a key k.
To decrypt the code, y

*/

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> answer(n,0);
        if(k>0){
            for(int i=0; i<n; i++){
                int sum = 0;
                for(int j =1; j<=k; j++){
                    sum += code[(i+j)%n];
                }
                answer[i] = sum;
            }
        }
        else if (k < 0){
            for(int i =0;i<n;i++){
                int sum = 0;
                for(int j =-1; j>=k; j--){
                    int index = (n+(i+j))%n;
                    sum+= code[index];
                }
                answer[i] = sum;
            }
        }
        
            return answer;
    }
};
