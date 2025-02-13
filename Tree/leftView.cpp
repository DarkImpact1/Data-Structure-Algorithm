/*
same as right view but there we were storing the value of last node present in queue
here we have to store the first value of node present in the queue

*/


class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
        vector<int> ans;
        if(!root) return ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                Node* front = q.front();
                q.pop();
                if(i==0){
                    ans.push_back(front->data);
                }
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
        }
        return ans;
    }
};
