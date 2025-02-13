#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

vector<int> rightView1(Node* root){
    vector<int> ans;
    if(!root) return ans;
    
    map<int, int> mpp;// mpp<level, val>
    queue<pair<Node*,int>> q; // q(node,level)
    q.push({root,0});
    while(!q.empty()){
        auto front = q.front();
        q.pop();
        Node* node = front.first;
        int level = front.second;
        mpp[level] = node->data;
        if(node->left){
            q.push({node->left, level+1});
        }
        if(node->right){
            q.push({node->right,level+1});
        }
    }
    for(auto it : mpp){
        ans.push_back(it.second);
    }
    return ans;
}


// another method withour using map
// directly store the value of last node of level

vector<int> rightView2(Node* root){
    vector<int> ans;
    if(!root) return ans;
    
    queue<pair<Node*,int>> q;// store node, and level
    q.push({root,0});
    
    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i<size; i++ ){
            auto front = q.front();
            q.pop();
            Node* node = front.first;
            int level = front.second;
            if(i==size-1){
                ans.push_back(node->data);
            }
            if(node->left) q.push({node->left,level+1});
            if(node->right)q.push({node->right,level+1});
        }
    }
    return ans;
}


// more optimised code will 
// since we are only including the right most node so we don't need
// we do not need to store the level in queue

vector<int> rightView3(Node* root){
    vector<int> ans;
    if(!root) return ans;
    
    queue<Node*> q; // let's only store the node 
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        for(int i=0; i<size;i++){
            Node* node = q.front();
            q.pop();
            if(i== size-1){
                ans.push_back(node->data);
            }
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
    return ans;

}


// Helper function to print the result
void printRightView(const vector<int>& result) {
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->right->right->right = new Node(7);

    vector<int> result = rightView1(root);
    printRightView(result);

    return 0;
}
