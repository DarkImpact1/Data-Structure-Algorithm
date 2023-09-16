// Insertion at end of linked list
#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct node
{
	int data;
	struct node* next;
} node;

/*Basically this function will take a linked list then and item which you want to insert 
after this it will create ia new node and then insert the item in that node. Afterward 
it is creating another pointer which is a copy of linked list and then traverse the LL
unless it found NULL. As soon as it found NULL loop will be break and then that last 
node->next will be new node and newnode->next will be NULL

Time complexity 
	for all the case--> O(n)
*/
//----------------------------------------------------------------------------------

node* insert_at_end(node* start, int item)
{
	node* newptr = (node*)malloc(sizeof(node));
	newptr->data = item;
	node* p = start;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next = newptr;
	newptr->next = NULL;
	return start;
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
// entry point
int main()
{
	node* head = (node*)malloc(sizeof(node));
	head->data = 1;
	head->next = NULL;
	// till here a node head is created in which I have inserted the data and it is pointing to NUll
	cout<<"Before inserting : "<<endl;
	traverse(head);
	cout<<"After inserting element at the end : "<<endl;
	head = insert_at_end(head,2);
	traverse(head);
}
