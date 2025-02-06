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
    int getHeight(TreeNode* root, bool& isBal){
        if(root == nullptr){
            return 0;
        }
        int lh = getHeight(root->left, isBal);
        int rh = getHeight(root->right, isBal);
        if(abs(lh-rh) > 1){
            isBal = false;
        }
        return 1+max(lh,rh);
    }

    bool isBalanced(TreeNode* root) {
        bool ans = true;
        int h =getHeight(root, ans);
        return ans;
        // return height(root) != -1 ? true : false;
    }
};
