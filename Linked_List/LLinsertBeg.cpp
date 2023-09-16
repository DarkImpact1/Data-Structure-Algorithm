// Insertion at the beggining in linked list
#include<iostream>
#include<stdlib.h>
using namespace std;
// I used typedef to get rid of typing "struct node *" instead of this I can write "node*"
typedef struct node
{
    int data;
    struct node *next;// self referencing structure 
                        // --> which contains a pointer which is pointing to itself 
} node;// I gave this name to struct node;
//----------------------------------------------------------------------------------
// this function will return a new node after inserting a node at the beggining
node* Insert_at_beg(node *ptr,int item)
{
	// creating a node 
	node* new_node  = (node*)malloc(sizeof(node));
	new_node->data = item;
	new_node->next = ptr;
	return new_node;
}

// this function will traverse the array and display the data in it.
void traverse(node* ptr)
{
	while(ptr!=NULL)
	{
		cout<<"item : "<<ptr->data<<endl;
		ptr = ptr->next;
	}
}
int main()
{
	node* head = (node*)malloc(sizeof(node));
	head->data = 1;
	head->next = NULL;
	// till here a node head is created in which I have inserted the data and it is pointing to NUll
	cout<<"Before inserting : "<<endl;
	traverse(head);
	head = Insert_at_beg(head,0);
	cout<<"After inserting element at beggining : "<<endl;
	head = Insert_at_beg(head,1);
	head = Insert_at_beg(head,2);
	traverse(head);
}
