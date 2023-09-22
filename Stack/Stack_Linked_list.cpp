#include<iostream>
using namespace std;
class Node
{
    public:
        int data;
        Node *next;
};
Node *top = NULL;
int Len()
{
    Node *temp = top;
    if(top == NULL)
    {
        return 0;
    }
    else
    {
        int count=0;
        while(temp != NULL)
        {
            count++;
            temp =temp->next;
        }
        return count;
    }
}
void Push(int x)
{
    Node *push_node = new Node();
    push_node->data = x;
    push_node->next  = top;
    top = push_node;
    cout<<endl<<x<<" inserted succesfully ";
}
void Pop()
{
    if(top == NULL)
    {
        cout<<"\nStack is empty ..";
    }
    else
    {
        Node *temp = top;
        top = top->next;
        cout<<"\nData at the Popped node is : "<<temp->data;
        delete temp;
    }
}
void Peek()
{
    Node *temp=top;
    if(top == NULL)
    {
        cout<<"\nStack is empty ..";
    }
    else
    {
        cout<<"\nData in top node is : "<<temp->data;
    }
}
void Display()
{
    if(top == NULL)
    {
        cout<<"\nStack is empty .. ";
    }
    else
    {       
        Node *ptr=top;
        cout<<"\nElement in Stack : ";
        while(ptr!=NULL)
        {
            cout<<ptr->data<<ends;
            ptr=ptr->next;
        }
        cout<<endl;
    }
}
int main()
{
    int Start= 1,choice;
    cout<<"\nSelect your choice : "<<endl;
    cout<<"\n1-> Push\n2-> Pop\n3-> Peek\n4-> Display\n5-> Length of Stack\n6-> Exit\n";
    while(Start)
    {
        cout<<"\nEnter your choice : ";cin>>choice;
        switch (choice)
        {
        case 1 :
            int data;
            cout<<"\nEnter the data which you want to push in the stack : ";cin>>data;
            Push(data);
            break;
        case 2 :
            Pop();
            break;
        case 3 :
            Peek();
            break;
        case 4 :
            Display();
            break;
        case 5 :
            cout<<"\nNumber of node in stack is/are : "<<Len();
            break;
        case 6 :
            cout<<"\nExiting.....";
            Start = 0;
            break;
        default:
            cout<<"\nWrong choice .....";
            break;
        }
    }
}
