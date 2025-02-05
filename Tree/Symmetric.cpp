// is tree Symmetric

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

    bool areMirr(TreeNode* l, TreeNode* r){
        if(l== nullptr && r == nullptr){
            return true;
        }
        if(l==nullptr || r == nullptr){
            return false;
        }
        bool rootsame = l->val == r->val;
        bool leftTreeSym = areMirr(l->left,r->right);
        bool rightTreeSym = areMirr(l->right,r->left);
        return rootsame && leftTreeSym && rightTreeSym;
    }
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr){
            return true;
        }
        return areMirr(root->left, root->right);
    }
};
