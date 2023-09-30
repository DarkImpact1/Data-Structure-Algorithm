// Implementation of queue using linked list
// first in first out first out (FIFO)
#include<iostream>
using namespace std;

class node
{

	public:
	int data;
	node *next;
	node(int value)
	{
		data = value;
		next = NULL;		
	}
};
node *front = NULL;
node *rear = NULL;

void enqueue(int num)
{
	node *newnode = new node(num);
	if(front == NULL && rear == NULL)
	{
		front = rear = newnode;
	}
	else
	{
		rear->next = newnode;
		rear = newnode;
	}	
	cout<<"Node enqueued successfully."<<endl;
}
void display()
{
	if(front == NULL && rear == NULL)
	{
		cout<<"Queue is empty."<<endl;
		return;
	}
	node *temp = front;
	cout<<"Element in queue are : ";
	while(temp != NULL)
	{
		cout<<temp->data<<endl;
		temp = temp->next;
		cout<<"                     : ";
	}
	cout<<endl;
}
void dequeue()
{
	if(front == NULL && rear == NULL)
	{
		cout<<"Queue is empty."<<endl;
	}
	else
	{
		node *temp = front;
		cout<<"Dequeued node contains : "<<temp->data<<endl;
		front = front->next;
		delete temp;
	}
}
int main()
{
	cout<<"\nChoose you choice : \n";
	cout<<"\n1-> Enqueue node in queue : ";
	cout<<"\n2-> Dequeue node from queue : ";
	cout<<"\n3-> Display node in queue : ";
	cout<<"\n4-> Exit..\n";
	int choice;
	bool start = true;
	while(start)
	{
		cout<<"Enter you choice : ";cin>>choice;
		switch(choice)
		{
			case 1: 
				int num;
				cout<<"Enter the value you want to put in node : ";cin>>num;
				enqueue(num);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				cout<<"Exiting...."<<endl;
				start = false;
				break;
		}
	}
}
