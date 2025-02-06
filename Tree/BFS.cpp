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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        if(root == nullptr) return answer;

        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int size = que.size();
            vector<int> level;
            for(int i=0; i<size;i++){
                TreeNode* front = que.front();
                if(front->left != nullptr) que.push(front->left);
                if(front->right != nullptr) que.push(front->right);
                que.pop();
                level.push_back(front->val);
            }
            answer.push_back(level);
        }
        return answer;
    }
};
