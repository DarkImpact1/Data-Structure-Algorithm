// Insertion at given index of linked list
#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct node
{
	int data;
	struct node* next;
} node;


node* insert_at_index(node* start, int item, int index)
{
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = item;
	node* p = start;
	int i=0;
	while(i!=index-1)
	{
		p=p->next;
		i++;
	}
	newnode->next = p->next;
	p->next = newnode;
	return start; 
}
// this function will traverse the array and display the data in it.
void traverse(node* ptr)
{
	cout<<"item : ";
	while(ptr!=NULL)
	{
		cout<<ptr->data<<ends;
		ptr = ptr->next;
	}
	cout<<endl;
}
int main()
{
	node* head = (node*)malloc(sizeof(node));
	node* first = (node*)malloc(sizeof(node));
	head->data = 1;
	head->next = first;
	first->data = 3;
	first->next = NULL;
	cout<<"Before insertion : "<<endl;
	traverse(head);
	head = insert_at_index(head,2,1);
	cout<<"After inserting 10 at 1 : "<<endl;
	traverse(head);
	head = insert_at_index(head,18,2);
	cout<<"After inserting 18 at 2 : "<<endl;
	traverse(head);
	return 0;
}
