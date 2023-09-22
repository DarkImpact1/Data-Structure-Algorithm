#include<iostream>
using namespace std;
#define size 5 
int top = -1;
int Stack[size];
void Push(int value)
{
    if(top == (size-1))
    {
        cout<<"\nStack overflow.. ";
    }
    else
    {
        top++;
        Stack[top]=value;
    }
}
void Pop()
{
    if(top == -1)
    {
        cout<<"\n Stack underflow ..";
    }
    else
    {
        int temp = Stack[top];
        cout<<"\nPopped item is : "<<temp;
        top--;
    }
}
void Peek()
{
    if(top == -1)
    {
        cout<<"\n Stack underflow ..";
    }
    else
    {
        int temp = Stack[top];
        cout<<"\nTop item is : "<<temp;
    }
}
void Display()
{
    if(top > -1)
    {
        cout<<"\nItems in Stack are : ";
        for(int i = top; i>=0; i--)
        {
            cout<<Stack[i]<<ends;
        }
        cout<<endl;
    }
    else
    {
    	cout<<"\nStack is empty. Push some element in it ";
	}
}
int main()
{
    int Start= 1,choice;
    cout<<"\nSelect your choice : "<<endl;
    cout<<"\n1-> Push\n2-> Pop\n3-> Peek\n4-> Display\n5-> Exit\n";
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
            cout<<"\nExiting.....";
            Start = 0;
            break;
        default:
            cout<<"\nWrong choice .....";
            break;
        }
    }
}
