#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct node
{
	struct node *prev;
	int data;
	struct node *next;// remember you can't initialize variable while you are creating it in structure
					  // because it only creating data type, not allocating the memory.
}dllnode;
dllnode *head;

void Create_Doubly_LL()
{
	head = NULL; 
	dllnode *temp;

	int choice = 1;
	while(choice)
	{
		dllnode *newnode = (dllnode*)malloc(sizeof(dllnode));
		newnode->prev = NULL;
		cout<<"Enter the data : "; cin>>newnode->data;
		newnode->next = NULL;
		if(head == NULL)
		{
			head = temp = newnode;
		}
		else
		{
			temp->next = newnode;
			newnode->prev = temp;
			temp = newnode;
		}
		cout<<"Want to add more node in Doubly Linked list :\n1-> yes     0-> no      : ";cin>>choice;
	}
}

void Display()
{
	dllnode *temp;
	temp = head;
	while(temp != NULL)
	{
		cout<<temp->data<<endl;
		temp = temp->next;
	}
}
int main()
{
	Create_Doubly_LL();
	Display();
	return 0;
}
