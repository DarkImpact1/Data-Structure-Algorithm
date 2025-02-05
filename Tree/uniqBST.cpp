/*

Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of 
unique values from 1 to n.

*/

class Solution {
public:
    int numTrees(int n) {
        // this can be solved using catalan number 
        int cat[n+1];
        cat[0] = 1;
        for(int i=1; i<=n; i++){
            cat[i]= 0;
            for(int j =0; j<i; j++){
                cat[i] = cat[i] + (cat[j] * cat[i-j-1]);
            }
        }
        return cat[n];
    }
};
