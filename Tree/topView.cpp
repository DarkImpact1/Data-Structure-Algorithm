/*
       1
   2       3
4     5 6      5    // 42135 answer

approach
same cartesian plane concept moving left  means moving to -ve x axis ,, and moving right means +x axis
map will containg the x cordinate, and value -> and will only push those value of those coordinate whose value is not present 

*/

class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        vector<int> answer;
        if(!root) return answer;
        map<int,int> mpp; // map<vertical, val>
        queue<pair<Node*,int>> q; // que<Node, vertical>
        q.push({root,0});
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            Node* node = front.first;
            int line = front.second;
            if(mpp.find(line) == mpp.end()){
                mpp[line] = node->data;
            }
            if(node->left){
                q.push({node->left,line-1});
            }
            if(node->right){
                q.push({node->right,line+1});
            }
        }
        for(auto it : mpp){
            answer.push_back(it.second);
        }
        return answer;
    }
};
