


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
// Another approach to solve the same without using another function
    int minDepth(TreeNode* root) {
        if (!root) return 0; // Base case: Empty tree has depth 0

        if (!root->left) return 1 + minDepth(root->right); // If left is null, go right
        if (!root->right) return 1 + minDepth(root->left); // If right is null, go left

        return 1 + min(minDepth(root->left), minDepth(root->right)); // Find min depth of both subtrees
    }

    int minDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        return depth(root);
    }
};
