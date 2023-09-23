/*This program will basically tell you either the expression which you write have a balanced paranthesis or not
Conditions to check balancing
    if you find any opening bracet then Push it into stack
    1-> if you find any closing bracket then pop it and while popping 
        if stack is empty then ---- paranthesis is not balanced 
            here's an example which will clarify the sentence A+B)-(a*b)
            
    2->And Once you reach the end of expression then check if you stack have some value in it 
    then unbalanced paranthesis were there in that expression 
    example --> A(a+b)((d-g)                   */
#include<iostream>
#include<string>
using namespace std;
#define size 100
char stack[size];
int top = -1;
void Push(char opening)
{
    if(top == (size-1))
    {
        cout<<"\nStack overflow.. Kindly increase the size of Stack :-) ";
    }
    else
    {
        top++;
        stack[top]=opening;
        cout<<"\nInserted successfully..";
    }
}
void Pop()
{
    char temp = stack[top];
    cout<<"\nPopped "<<temp<<endl;
    top--;
}
bool Is_Empty()
{
    if(top ==  -1)
        return true;
    else
        return false;
}
bool Is_Paranthesis_Balanced(string expression)
{
    for(int i=0; expression[i]!='\0';i++)
    {
    	char c = expression[i];
//    	cout<<c;
        if((c == '(') || (c == '{') || (c == '['))
        {
            Push(c);
        }
        else if ((c == ')') || (c == '}') || (c == ']'))
        {
            // During Pop operation if stack is empty then it will return false 
            // Therefore paranthesis is not Balanced
            if(Is_Empty()) return false;
            else
            {
                Pop();
            }
        }
    }
    if(Is_Empty()) return true;
    else return false;
}
int main()
{
    string expression;
    cout<<"Enter the expression : ";
    getline(cin,expression);
    bool answer = Is_Paranthesis_Balanced(expression);
    cout<<"\nThe expression which you provide has : ";
    if(answer == true)
    {
        cout<<"\nBalanced paranthesis...";
    }
    else{
        cout<<"\nUnbalanced paranthesis...";
    }
}

