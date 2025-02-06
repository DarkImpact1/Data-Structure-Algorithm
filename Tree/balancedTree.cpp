/*
check if tree is balanced binary tree
/*


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
    int height(TreeNode* root){
        if(root == nullptr) return 0;


        int lh = height(root->left);
        if(lh == -1) return -1; // if at any moment we find left tree is unbalanced return -1;
        int rh = height(root->right);
        if(rh == -1) return -1; // if at any moment we find right tree is unbalanced we return -1;

        if(abs(lh - rh) > 1) return -1; // if not then checking whole tree if it is unbalanced then return -1;


        return 1 + max(lh, rh); // calculate hright of tree
    }
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};
