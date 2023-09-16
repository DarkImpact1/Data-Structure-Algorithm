//    ------------------------Linked List----------------------------    
#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
	int data;
	struct node* next;
};
struct node* insert(struct node* ptr,int num)
{
	
	struct node* p=ptr;
	int item,i=0;
	cout<<"Enter the item you want to insert : ";
	while (i<num)
	{
		cin>>item;
		struct node* newnode = (struct node*)malloc(sizeof(struct node));
		p->next = newnode;
		newnode->data = item;
		newnode->next = NULL;	
		i++;	
	}
	return ptr;
	
}
void display(struct node* head)
{
	cout<<"your linked list is : "<<endl;
	while(head!= NULL)
	{
		cout<<head->data<<ends;
		head= head->next;
	}
	cout<<endl;
}
int main()
{
	struct node* head = (struct node*)malloc(sizeof(struct node));
	head->data = 1;
	head->next = NULL;
	int n;
	cout<<"Enter the number of items you want to insert in Linked list : ";
	cin>>n;
	head = insert(head,n);
	display(head);
}
