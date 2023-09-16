// it is linear data structure which is far better than array 
// consist of two things
    // --> data/information
    // --> pointer ( holding address of next node)
// it's advantages
    // --> easy to extend and shrink
    // --> easy to insert and delete
    // --> avoid memory wastage
// disadvantage
    // -->size increase with the increment in data because it will requires extra memory for pointer 
    // --> random access memory is not allowed because we don't know where will be the next data
#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    struct node *link;// self referencing structure 
                        // --> which contains a pointer which is pointing to itself 
};
void linkedlisttraversal(struct node * ptr)
{
    while(ptr!=NULL)
    {
        cout<<"Data is : "<<ptr->data<<endl;
        ptr = ptr -> link;
    }
}
int main()
{
    struct node *head;// creating first node;
    struct node *first;
    struct node *second;
    // allcationg memeory to the first ptr and linking to the next 
    head = (struct node *)malloc(sizeof(struct node));
    first = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    // adding data to dead and linking to first node
    head -> data = 5;
    head -> link = first;
    // adding data to first and linking to second node
    first -> data = 8;
    first -> link = second;
    // adding data to second node and terminating it
    second -> data = 99;
    second -> link = NULL;
    linkedlisttraversal(head);
    return 0;
}
