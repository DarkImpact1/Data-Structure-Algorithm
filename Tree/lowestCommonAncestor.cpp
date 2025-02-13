/*
as soon as you found you p or q return p or q respectively or else return null

if you don't found left but have right return right
if you don't found right but have left return left
or if you found both left and right under the same root directly return root because you are at the answer
  */


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // return null, or p or q if any of them is found
        if(root == NULL || root == p || root == q){
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p,  q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(!left) return right;
        else if(!right) return left;
        // if both left and right is found then you are the the answer
        return root;
    }
};
