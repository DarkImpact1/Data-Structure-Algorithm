// Implementation of Queue using Array FIFO/LILO
#include<iostream>
using namespace std;
#define size 10
int Queue[size];
int front=-1, rear=-1;
void enqueue(int data)
{
    if(rear == (size-1))
    {
        cout<<"Queue Overflow....";
    }
    else if ( front == -1 && rear == -1)
    {
        front = rear = 0;
        Queue[rear] = data;
        cout<<"Data "<<data<<" queued "<<endl;
    }
    else
    {
        rear++;
        Queue[rear] = data;
        cout<<"Data "<<data<<" queued "<<endl;
    }
}
void dequeue()
{
    if(front == -1 & rear == -1)
    {
        cout<<"Queue underflow..."<<endl;
    }
    else if(front == rear)
    {
        cout<<"Only single/last element is in queue : "<<Queue[front]<<endl;
        cout<<"Dequeued Successfully "<<endl;
        front = rear = -1;
    }
    else
    {
        int temp = Queue[front];
        cout<<"Dequeued element is : "<<temp<<endl;
        front++;
    }
}
void display()
{
    if(front == -1 & rear == -1)
    {
        cout<<"Queue is empty..."<<endl;
    }
    else
    {   
        cout<<"Elements in Queue are : ";
        for(int i = front; i<=rear;i++)
        {
            cout<<Queue[i]<<" ";
        }
        cout<<endl;
    }
}
void Display_front()
{
    if(front == -1 & rear == -1)
    {
        cout<<"Queue is empty..."<<endl;
    }
    else
    {
        int fr = Queue[front];
        cout<<"Front element in queue is : "<<fr<<endl;
    }
}
void Display_rear()
{
    if(front == -1 & rear == -1)
    {
        cout<<"Queue is empty..."<<endl;
    }
    else
    {
        int rr = Queue[rear];
        cout<<"Last element in queue is : "<<rr<<endl;
    }
}
bool Is_Full()
{
    if(rear == (size-1))
    {
        return true;
    }
    return false;
}
bool Is_Empty()
{
    if(front == -1 & rear == -1)
    {
        return true;
    }
    return false;
}
int main()
{
    cout<<"1-> To perform Enqueue : "<<endl;
    cout<<"2-> To perform Dequeue : "<<endl;
    cout<<"3-> To Display element : "<<endl;
    cout<<"4-> To Display Front element : "<<endl;
    cout<<"5-> To Display Rear element : "<<endl;
    cout<<"6-> To Check if Full : "<<endl;
    cout<<"7-> To Check if Empty : "<<endl;
    cout<<"8-> To Exit : "<<endl;
    while(true)
    {
        int choice;
        cout<<"Enter your choice : ";cin>>choice;
        if(choice == 1)
        {
            int value;
            cout<<"Enter the value you want to place in queue : ";cin>>value;
            enqueue(value);
        }
        else if (choice == 2)
        {
            dequeue();
        }
        else if (choice == 3)
        {
            display();
        }
        else if (choice == 4)
        {
            Display_front();
        }
        else if (choice == 5)
        {
            Display_rear();
        }
        else if (choice == 6)
        {
            if(Is_Full()) cout<<"Queue is Full : "<<endl;
            else cout<<"Queue is not Full : "<<endl;;
        }
        else if (choice == 7)
        {
            if(Is_Empty()) cout<<"Queue is empty : "<<endl;
            else cout<<"Queue is not empty : "<<endl;
        }
        else if(choice == 8)
        {
            cout<<"Exiting...."<<endl;
            break;
        }
        else
        {
            cout<<"Wrong choice "<<endl;
        }
        
    }
}
