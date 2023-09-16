#include<iostream>
using namespace std;

class Node
{
	int data;
	Node *prev;
	Node *next;
	public:
	// creating default constructor
	Node(){
	}
	//constructor with parameter
	Node(int new_data)
	{
		data = new_data;
		prev = NULL;
		next = NULL;
	}
	Node *head = NULL;
	Node *tail;
	// creating doubly linked list 
	void Create()
	{
		int choice = 1,i=0;	
		while(choice)
		{
		
			int value;
			cout<<"Enter the data in "<<i<<" node : ";cin>>value;
			Node *newnode = new Node(value);
			if(head == NULL)
			{
				head = tail = newnode;// with using tail we can directly insert data at end;
			}
			else
			{
				tail->next = newnode;
				newnode->prev = tail;
				tail = newnode;
			}
			cout<<"Want to add more node in Doubly Linked list :\n1-> yes     0-> no      : ";cin>>choice;
			i++;
		}
	}
	// function to display/traverse all the data in doubly linked list 
	void Display()
	{
		Node *tail;
		tail = head;
		int i=0;
		while(tail!=NULL)
		{
			cout<<"The data in "<<i<<" node : "<<tail->data<<endl;
			tail = tail->next;
			i++;
		}
	}
	void Insert_Beg(Node* ibhead, int data)
	{
//		Node *tail = head;
		Node* beg_node = new Node(data);
		if(ibhead == NULL)
		{
			ibhead = tail = beg_node;
		}
		else
		{
			ibhead->prev = beg_node;
			beg_node->next = ibhead;
			ibhead = beg_node;
		}
	}
	void Insert(Node *ihead, Node *itail)
	{
		int choice,insert = 1;
		cout<<"\n0-> Insert at beggining\n1-> Insert at random index\n2-> Insert after index\n3-> Insert at End\n4-> Exit\n";
		while(insert)
		{
			cout<<"\n-----------------------------: where do you want to insert :-----------------------------\n"<<endl;
			cin>>choice;
			if(choice == 0)
			{
//				cout<<"beg\n";
				Insert_Beg(ihead,10);
			}
			else if(choice == 1)
			{
				cout<<"randon\n";
			}
			else if (choice == 2)
			{
				cout<<"after\n";
			}
			else if(choice == 3)
			{
				cout<<"end\n";
			}
			else
			{
				cout<<"Exiting..."<<endl;
				break;
			}
			cout<<"Want to insert more : 0 -> NO     1 -> YES   : ";cin>>insert;
		}
		return ;
	}
	
};
int main()
{
	Node Doubly_linked_list;
	Doubly_linked_list.Create();
	
	Doubly_linked_list.Insert(Doubly_linked_list.head,Doubly_linked_list.tail );
	Doubly_linked_list.Display();
}
