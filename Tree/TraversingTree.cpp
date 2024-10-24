#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

// Definition for a binary tree node
struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
    // BFS function to traverse the binary tree (not DFS as stated in the original code)
    vector<vector<int>> BFS(Node* root) {
        vector<vector<int>> bfs_ans;
        if (root == nullptr) return bfs_ans;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++) {
                Node* l_node = q.front();
                q.pop();
                if (l_node->left != nullptr) q.push(l_node->left);
                if (l_node->right != nullptr) q.push(l_node->right);
                level.push_back(l_node->val);
            }
            bfs_ans.push_back(level);
        }
        return bfs_ans;
    }
    
    // Pre-order traversal without recursion
    vector<int> preOrderWithoutRecursion(Node* root) {
        vector<int> preOrder;
        if (root == nullptr) return preOrder; 
        stack<Node*> st;
        st.push(root);
        while (!st.empty()) {
            root = st.top();
            st.pop();
            preOrder.push_back(root->val);
            // Push right first so left is processed first
            if (root->right != nullptr) st.push(root->right);
            if (root->left != nullptr) st.push(root->left);
        }
        return preOrder;
    }
    // Inorder Traversal without recursion
    vector<int> inOrderWithoutRecursion(Node* root){
        vector<int> inOrder;
        if(root == nullptr) return inOrder;
        Node* node = root;
        stack<Node*> st;
        while(true){
            if(node != nullptr){
                st.push(node);
                node = node ->left;
            }else{
                if(st.empty() == true) break;
                node = st.top();
                st.pop();
                inOrder.push_back(node -> val);
                node = node -> right;
            }
        }
        return inOrder;
        
    }
    
    vector<int> postOrderWithoutRecursion(Node* root){
        vector<int> postOrder;
        if(root == nullptr) return postOrder;
        stack<Node*> st;
        st.push(root);
        while(!st.empty()){
            root = st.top();
            st.pop();
            postOrder.push_back(root -> val);
            // Push left first so right is processed first
            if(root -> left != nullptr) st.push(root -> left);
            if(root -> right != nullptr) st.push(root -> right);
        }
        return postOrder;
    }
    

};

int main() {
    // Create the binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    Solution agent;
    cout<<"Traversing Breadth First "<<endl;
    // Perform BFS traversal
    vector<vector<int>> result = agent.BFS(root);
    for (auto level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
    cout<<"Traversing PreOrder without Using Recursion "<<endl;
    // Perform pre-order traversal without recursion
    vector<int> preOrder = agent.preOrderWithoutRecursion(root);
    for (int val : preOrder) {
        cout << val << " ";
    }
    
    cout<<"\nTraversing InOrder without using Recursion "<<endl;
    vector<int> inOrder = agent.inOrderWithoutRecursion(root);
    for (int val : inOrder) {
        cout << val << " ";
    }
    
    cout<<"\nTraversing PostOrder without using Recursion "<<endl;
    vector<int> postOrder = agent.postOrderWithoutRecursion(root);
    for (int val : postOrder) {
        cout << val << " ";
    }


    

    return 0;
}
