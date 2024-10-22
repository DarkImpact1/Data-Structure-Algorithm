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
        if (root == nullptr) return preOrder; // Fix return variable
        stack<Node*> st;
        st.push(root);
        while (!st.empty()) {
            Node* node = st.top(); // Declare node variable with Node* type
            st.pop();
            preOrder.push_back(node->val);
            // Push right first so left is processed first
            if (node->right != nullptr) st.push(node->right);
            if (node->left != nullptr) st.push(node->left);
        }
        return preOrder;
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

    return 0;
}
