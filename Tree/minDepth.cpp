


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
    int depth(TreeNode* root){
        if(root == nullptr){
            return INT_MAX; // if is not at leaf if you will return 0 then it may lead to a problem 
          /*
                   3
              2         4
           5     4    1
            check for this problem then you will get it
            */
        }
        if(root->left == nullptr && root->right == nullptr){
            return 1; // if leaf return 1
        }
        int leftD = depth(root->left);
        int rightD = depth(root->right);
        return 1 + min(leftD, rightD);

    }
    int minDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        return depth(root);
    }
};
