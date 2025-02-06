// Diameter is defined as the maximum path between two node

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getD(TreeNode* root,int& dia){
        if(root == nullptr){
            return 0;
        }
        int lh = getD(root->left, dia);
        int rh = getD(root->right, dia);
        dia = max(lh+rh,dia);
        return 1+ max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        getD(root, dia);
        return dia;

    }
};
