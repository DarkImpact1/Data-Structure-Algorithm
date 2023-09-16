#include<iostream>
using namespace std;
class Node
{
    public:
        int data;
        Node *next;
};
Node *head = NULL;
int Len()
{
    Node *temp;
    temp = head;
    int length=0;
    if(temp == NULL)
    {
    	return 0;
	}
	else
	{
	    while(temp !=NULL)
	    {
	        temp = temp->next;
	        length ++;
	    }
	    return length;
	}
}
void Insert_beg(int value)
{
    Node *newnode =new  Node();
    newnode->data = value;
    newnode->next = head;
    head = newnode;
}
void Insert_End(int value)
{
    Node *endnode = new Node();
    endnode->data = value;
    if(head == NULL)
    {
        head = endnode;
    }
    else
    {
    	Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = endnode;
        endnode->next = NULL;
    }
}
void Insert_at_Pos(int value,int pos)
{
    if(pos == 1)
    {
        Insert_beg(value);
    }
    else if(pos == Len())
    {
        Insert_End(value);
    }
    else
    {
        Node *inode = new Node();
        inode->data = value;
        Node *temp = head;
        int i=1;
        while(i<(pos-1))
        {
            temp = temp->next;
        }
        inode->next - temp->next;
        temp->next = inode;
    }
}
void Traverse()
{
    Node *temp;
    temp = head;
    cout<<"Value in linked list : ";
    while(temp !=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
void Delete_from_Beg()
{
    if(head == NULL)
    {
        cout<<"List is empty "<<endl;
    }
    else
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}
void Delete_From_End()
{
    Node *temp, *prev_node;
    temp= head;
    while(temp ->next != 0)
    {
        prev_node = temp;
        temp  = temp->next;
    }
    if(temp == head)
    {
        head = NULL;
    }
    else{
        prev_node -> next = NULL;
    }
    delete temp;
}
void Delete_From_Pos(int pos)// delete from specific position 
{
    Node *temp = head, *next_node;
    if(temp == NULL)
    {
        cout<<"List is empty. "<<endl;
    }
    else if(pos == 1)
    {
    	Delete_from_Beg();
	}
	else if(pos == Len())
	{
		Delete_From_End();
	}
    else if(pos > Len())
    {
    	cout<<"Please enter valid position : "<<endl;
	}
    else
    {
        int i=1;
        while(i<(pos-1))
        {
            temp = temp->next;
            i++;
        }
        next_node =temp->next;
        if(head -> next == NULL)// it means only 1 node is present in the list
        {
            head = NULL;
            delete temp;
        }
        else// if more than one node is present then 
        {
            
            temp->next = next_node ->next;
            delete next_node;
        }
    }
}
int main()
{
    cout<<"Choices are "<<endl;
    cout<<"1-> Insertion "<<endl;
    cout<<"2-> Deletion "<<endl;
    cout<<"3-> Traverse "<<endl;
    cout<<"4-> Length of Linked list "<<endl;
    cout<<"5-> Exit "<<endl;
    bool start = true;
    while(start)
    {
    	int choice; 
		cout<<"\nEnter your choice : "; cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"b -> Beggining "<<endl;
            cout<<"e -> End "<<endl;
            cout<<"p -> Position "<<endl;
            char c;
            cout<<"Where do you want to insert : ";cin>>c;
            int num;
            cout<<"Enter value you want to insert : ";cin>>num;
            cout<<endl;
            switch (c)
            {
            case 'b':
                Insert_beg(num);
                break;
            case 'e':
                Insert_End(num);
                break;
            case 'p':
                int p;
                cout<<"Enter the position where you want to insert : ";cin>>p;
                Insert_at_Pos(num,p);
                break;
            default:
                cout<<"Incorrect choice : "<<endl;
                break;
            }
            break;
        case 2:
            cout<<"b -> Beggining "<<endl;
            cout<<"e -> End "<<endl;
            cout<<"p -> Position "<<endl;
            char ch;
            cout<<"From where do you want to delete : ";
            cin>>ch;
            cout<<endl;
            switch (ch)
            {
            case 'b':
                Delete_from_Beg();
                break;
            case 'e':
                Delete_From_End();
                break;
            case 'p':
                int p;
                cout<<"Enter the position where you want to delete : ";cin>>p;cout<<endl;
                Delete_From_Pos(p);
                break;
            default:
                cout<<"Incorrect choice : "<<endl;
                break;
            }
            break;
        case 3:
            Traverse();
            break;
        case 4:
            cout<<"Length of linked list is : "<<Len()<<endl;
            break;
        case 5:
            cout<<"Exiting....."<<endl;
            start = false;
            break;
        
        default:
            cout<<"Incorrect choice : "<<endl;
            break;
        }
    }

    return 0; 
}
