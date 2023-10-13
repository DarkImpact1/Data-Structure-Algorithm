#include<iostream>
#include <windows.h>
using namespace std;
// Function to change text color
void setColor(int colorCode) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, colorCode);
}

void Red()
{
	setColor(4);
}
void Green()
{
	setColor(2);
}
void Blue()
{
	setColor(1);
}
void Cyan()
{
	setColor(3);
}
void Yellow()
{
	setColor(6);
}
void Grey()
{
	setColor(8);
}
void Reset()
{
	setColor(7);
}


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
	Blue();cin>>x;Reset();
	// base condition to terminate the recursive call
	if(x == -1)
	{
		return NULL;
	}
	newnode->data = x;
	// recursive call for left child
	cout<<"Enter the left child of : ";
	Red();cout<< x <<endl;Reset();
	newnode->left_child = create();
	// recursive call for right child
	cout<<"Enter the right child of : ";
	Red();cout<< x <<endl;Reset();
	newnode->right_child = create();
	
	return newnode;	
}
void traverse_preorder(node *root)// root - left - right
{
	if(root == 0)
	{
		return;
	}
	Cyan();cout << root->data << ends;Reset();
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
	Cyan();cout << root->data << ends;Reset();
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
	Cyan();cout << root->data << ends;Reset();
}
void instruction()
{
	Grey();cout<<"1-> Creating tree :\n";
	cout<<"2-> PreOrder Traversal : \n";
	cout<<"3-> InOrder Traversal : \n";
	cout<<"4-> PostOrder Traversal : \n";Reset();
	Red();cout<<"0-> Exit. \n";Reset();
}

int main()
{
	node *head;
	Yellow();
	cout<<"Hello welcome to Tree Data Structre \n";
	Reset();
	instruction();
	int choice;
	bool start = true;
	while(start)
	{
		Green();cout<<"\nChoice -> ";Reset();
		Blue();cin>>choice;Reset();
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
				Red();cout<<"Exiting ..... \n";Reset();
				start = false;
				break;
			default:
				Red();cout<<"Check your choice : \n";Reset();
				break;
		}
			
	}
}
