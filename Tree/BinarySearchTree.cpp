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

// Inserting value in BST
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
    else if(root->data >val ) // insert value in left BST
    {
        root->left_child = Insert(root->left_child, val );
    }
    else // Insert value in right BST
    {
        root->right_child = Insert(root->right_child, val);
    }

}
void traverse_inorder(Node *root)// left - root - child  O(h)

{

	if(root == 0)
	{
		return;
	}
	traverse_inorder(root->left_child);
	cout << root->data << " ";
	traverse_inorder(root->right_child);
}
void DeallocateMemory(Node* root) // O(h)
{
    if (root == NULL) {
        return;
    }
    DeallocateMemory(root->left_child);
    DeallocateMemory(root->right_child);
    delete root; // Deallocate memory for the current node
    
}
bool Search(Node *root, int key)// O(h)
{
	if(root == NULL)
	{
		return false;
	}
	else if(key > root->data)// search in right BST
	{
		Search(root->right_child, key);
	}
	else if(key == root->data)
	{
		return true;
	}
	else//search in left BST
	{
		Search(root->left_child,key);
	}
}
// to search Inorder successor for the 3rd case of deletion
Node* InorderSuccessor(Node *root)
{
	while(root->left_child != NULL)
	{
		root = root->left_child;
	}
	return root;
}
Node* Delete(Node *root, int value)
{
	if(value > root->data)// delete from right BST
	{
		root->right_child = Delete(root->right_child,value);
	}
	else if (value < root ->data)// delete from left BST
	{
		root->left_child = Delete(root->left_child,value);
	}
	else
	{
		// when it's a leaf node 
		if(root->left_child == NULL && root->right_child == NULL)
		{
			return NULL;
		}
		// Case 1: when root->left == NULL
		else if(root->left_child == NULL)
		{
			return root->right_child;
		}
		else if (root->right_child == NULL)
		{
			return root->left_child;
		}
		else
		{
			Node *inordersuc = InorderSuccessor(root->right_child);
			root->data = inordersuc->data;
			root->right_child = Delete(root->right_child, inordersuc->data);
		}
		return root;
	}
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
    int key;
    cout<<"\nEnter the key you want to delete/Search in BST : ";cin>>key;
    if(Search(root,key)) 
	{
		Delete(root,key);
	}
    else cout<<"Key not found : "<<endl;
    traverse_inorder(root);
    cout<<endl;
    DeallocateMemory(root);
    cout<<"\nDeallocated successfully : ";
}
