/*
Properties : 
    1-> All nose of the left subtree are lesser than root node
    2-> All nosed of the right subtree are greater than root node
    3-> Duplicates are not allowed in BST
    4-> Left and Right subtree are also BST
    5-> Inorder Traversal of a BST gives an ascending Sorted array
            -> In order to check wether a tree is BST then traverse inorder and if you find ascending order then YES else NO
                9
              /   \
             7     15
           /   \  /  \
           4   8 14  16

*/

// Here's the code in create a BST
#include<iostream>
using namespace std;

struct Node
{
    Node *left_child;
    int data;
    Node *right_child;
};
Node *root = NULL;
Node* Insert(Node *root, int val)
{
    if(root == NULL)
    {
        Node *newnode = new Node();
        newnode->data = val;
        root = newnode;
        return root; 
    }
    else if (root->data == val)
    {
    	cout<<"Duplicates are not allowed in BST : "<<endl;
    	return root;
	}
    else if(root->data >val )
    {
        root->left_child = Insert(root->left_child, val );
    }
    else 
    {
        root->right_child = Insert(root->right_child, val);
    }

}
void traverse_inorder(Node *root)// left - root - child
{

	if(root == 0)
	{
		return;
	}
	traverse_inorder(root->left_child);
	cout << root->data << " ";
	traverse_inorder(root->right_child);
}
void DeallocateMemory(Node* root) {
    if (root == NULL) {
        return;
    }
    DeallocateMemory(root->left_child);
    DeallocateMemory(root->right_child);
    delete root; // Deallocate memory for the current node
    
}
int main()
{
    int choice,prev = -1;
    while(true)
    {
        cout<<"Enter element you want to insert in element (0 to stop inserting) : ";
        cin>>choice;
        if(choice == 0) break;
        else
        {
        	root = Insert(root,choice);
		}
        
    }
    traverse_inorder(root);
    // To delete the memory after occupied by dynamically allocation
    DeallocateMemory(root);
    cout<<"\nDeallocated successfully : ";
}
