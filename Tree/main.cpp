#include<iostream>
using namespace std;

struct node
{
	node *left_child;
	int data;
	node *right_child;
};
node *root = NULL;

node* create()
{
	node *newnode = new node();
	int x;
	cout<<"Enter the value you want to insert in node (-1 for no node) : ";
	cin>>x;
	// base condition to terminate the recursive call
	if(x == -1)
	{
		return NULL;
	}
	newnode->data = x;
	// recursive call for left child
	cout<<"Enter the left child of : "<< x <<endl;
	newnode->left_child = create();
	// recursive call for right child
	cout<<"Enter the right child of : "<< x <<endl;
	newnode->right_child = create();
	
	return newnode;	
}
void traverse_preorder(node *root)// root - left - right
{
	if(root == 0)
	{
		return;
	}
	cout << root->data << ends;
	traverse_preorder(root->left_child);
	traverse_preorder(root->right_child);
}
void traverse_inorder(node *root)// left - root - child
{

	if(root == 0)
	{
		return;
	}
	traverse_inorder(root->left_child);
	cout << root->data << ends;
	traverse_inorder(root->right_child);
}
void traverse_postorder(node *root)// left - right - root
{
	if(root == 0)
	{
		return;
	}
	traverse_postorder(root->left_child);
	traverse_postorder(root->right_child);
	cout << root->data << ends;
}
void instruction()
{
	cout<<"1-> Creating tree :\n";
	cout<<"2-> PreOrder Traversal : \n";
	cout<<"3-> InOrder Traversal : \n";
	cout<<"4-> PostOrder Traversal : \n";
	cout<<"0-> Exit. \n";
}

int main()
{
	node *head;
	cout<<"Hello welcome to Tree Data Structre \n";
	instruction();
	int choice;
	bool start = true;
	while(start)
	{
		cout<<"\nChoice -> ";
		cin>>choice;
		switch(choice)
		{
			case 1: 
				head = create();
				instruction();
				break;
			case 2:
				traverse_preorder(head);
				cout<<" are elements in tree : \n";
				break;
			case 3:
				traverse_inorder(head);
				cout<<" are elements in tree : \n";
				break;
			case 4:
				traverse_postorder(head);
				cout<<" are elements in tree : \n";
				break;
			case 0:
				cout<<"Exiting ..... \n";
				start = false;
				break;
			default:
				cout<<"Check your choice : \n";
				break;
		}
			
	}
}
