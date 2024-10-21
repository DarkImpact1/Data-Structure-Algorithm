#include <iostream>
#include <bits/stdc++.h>
#include<vector>
#include<queue>
using namespace std;


// Definition for a binary tree node
struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

// DFS function to traverse the binary tree
vector<vector<int>> DFS(Node* root) {
    vector<vector<int>> dfs_ans;
    if(root == nullptr) return dfs_ans;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        int size = q.size();
        vector<int> level;
        for(int i = 0; i < size; i++) {
            Node* l_node = q.front();
            q.pop();
            if(l_node->left != nullptr) q.push(l_node->left);
            if(l_node->right != nullptr) q.push(l_node->right);
            level.push_back(l_node->val);
        }
        dfs_ans.push_back(level);
    }
    return dfs_ans;
}

int main() {
    // Create the binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    vector<vector<int>> result = DFS(root);

    for(auto level : result) {
        for(int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
