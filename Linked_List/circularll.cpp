#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
	int data;
	struct node* next;
};
struct node* ccinsertbeg(struct node* head, int data)
{
	struct node* begptr = (struct node*)malloc(sizeof(struct node));
	begptr->data = data;
	struct node* p = head->next;
	while(p->next!=head)
	{
		p = p->next;
	}
	p->next = begptr;
	begptr->next = head;
	return begptr;
}
struct node* ccinsertpos(struct node* head, int data, int pos)
{
	struct node* ptr = (struct node*)malloc(sizeof(struct node));
	ptr->data = data;
	struct node* p = head;
	int i = 0;
	while(i<pos)
	{
		cout<<"finding position : "<<p->data<<endl;
		p = p->next;
		i++;
	}
	ptr->next = p->next;
	p->next = ptr;
	return head;
	
}
void traverse(struct node* head)
{
	struct node* ptr = head;
	do{
		cout<<ptr->data<<endl;
		ptr = ptr->next;
	}while(ptr!=head);
}
int main()
{
	struct node* head = (struct node*)malloc(sizeof(struct node));
	struct node* first = (struct node*)malloc(sizeof(struct node));
	head->data = 1;
	head->next = first;
	first->data = 3;
	first->next = head;
//	traverse(head);
	head = ccinsertbeg(head,0);
//	traverse(head);
	head = ccinsertbeg(head,9);
//	traverse(head);
	head = ccinsertpos(head, 2,2);
	traverse(head);
}
