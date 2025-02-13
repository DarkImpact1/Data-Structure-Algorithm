/*
same approach as top view but here we don't need to check in map whether the line is present, because we have to 
show the last element present in the line 

and in top view we have to only show the first element that is present in the line
(because we are looking from the top)

*/
vector<int> bottomView(Node* root){
vector<int> ans;
    if(!root) return ans;
    
    map<int, int> mpp;// mpp<line, val>
    queue<pair<Node*,int>> q; // q(node,line)
    q.push({root,0});
    while(!q.empty()){
        auto front = q.front();
        q.pop();
        Node* node = front.first;
        int line = front.second;
        mpp[line] = node->data;
        if(node->left){
            q.push({node->left, line-1});
        }
        if(node->right){
            q.push({node->right,line+1});
        }
    }
    for(auto it : mpp){
        ans.push_back(it.second)
    }
return ans;

}
