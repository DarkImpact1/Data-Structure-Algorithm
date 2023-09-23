// This program will convert infix expression to postfix/ reverse polish notation expression
#include<iostream>
/* 
If you want to add additional functionality of checking if paranthesis are balanced or not then 
Copy the Paranthesis_Balance.cpp and save it in your desktop and then include the path of file 
Make sure there should not the main in "Paranthesis_Balance.cpp" just comment it. then it will work properly
Else comment the 8 line */
#include "C:\\Users\\sony\\DeskTOP\\DSA\\Stack\\Paranthesis_Balance.cpp"
#include<string>
using namespace std;
#define size 100
char STACK[size];
int TOP = -1;
string operators = "+-*/^";
// this function will return 
	// true --> if c is operator
bool is_operator(char c)
{
    for(int i=0; operators[i]!='\0';i++)
    {
        if(c == operators[i])
        {
            return true;
        }
    }
    return false;
}
// Function to push operator in the STACK
void PUSH(char oprtr)
{
    if(TOP == (size-1))
    {
        cout<<"\nStack overflow.. Kindly increase the size of Stack :-) ";
    }
    else
    {
        TOP++;
        STACK[TOP]=oprtr;
//        cout<<"\nInserted successfully..";
    }
}
// Function to check wether STACK is empty or not
bool IS_EMPTY()
{
    if(TOP ==  -1)
        return true;
    else
        return false;
}
void POP()
{
    char temp = STACK[TOP];
//    cout<<"\nPOPped "<<temp<<endl;
    TOP--;
}
// Function to get the precedence of an operator
int precedence(char c) {
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    return 0; // For '('
}
// Function to convert infix expression to Postfix/reverse polish notation  
string postfix_converter(string expression)
{
    string postfix_expression;
    for(int i = 0; expression[i]!='\0';i++)
    {
        char c = expression[i];
      // if c is alpha numeric then add it to the postfix expression
        if(isalnum(c))
        {
            postfix_expression +=c;
        }
      // else if it is opening bracket push it in the stack
        else if(c == '(' || c == '{' || c == '[')
        {
            PUSH(c);
        }
      // else if it closing bracket then ..
        else if(c == ')' || c == '}' || c == ']')
        {
          // pop and add the operator at the end of postfix expression until it find opening bracket
            while(!IS_EMPTY() && (STACK[TOP] !='(' && STACK[TOP] !='{' && STACK[TOP] !='['))
            {
                postfix_expression += STACK[TOP];
                POP();
            }
          // once added all the operator after opening bracket remove all the opening bracket from the stack.
            if(!IS_EMPTY() && (STACK[TOP] == '(' || STACK[TOP] == '{'|| STACK[TOP] == '['))
            {
                POP();
            }
        }

        else if( is_operator(c))
        {
          /* 
          if stack is not empty and the precedence of the operator if less than equals to the top operator present in the stack
          then pop and add that operator to the last of postfix expression. then again check the same and repeat it until the condition
          fails.*/
            while(!IS_EMPTY() && precedence(c) <= precedence(STACK[TOP]))
            {
                postfix_expression += STACK[TOP];
                POP();
            }
          /*
          If while condition is not true then directly push the operator in the stack 
          */
            PUSH(c);
        }
    }
  /*
  At last pop and add the operator at the end od postfix expression until stack is empty
  */
    while(!IS_EMPTY())
    {
        postfix_expression += STACK[TOP];
        POP();
    }
    return postfix_expression;
    
}
int main()
{
    string expression, pexpression;
    cout<<"Enter the infix expression which you want to convert in Postfix notation : ";
    getline(cin,expression);
    /* if you're including one of function declared in "Paranthesis_Balance.cpp"  then this program
    will work properly else you just skip if & else condition, only execute the line which is 
    written in if condition. */
    if(Is_Paranthesis_Balanced(expression))
    {
	    pexpression = postfix_converter(expression);
	    cout<<"Postfix expression is : "<< pexpression<<endl;
	}
	else
	{
		cout<<"\nMake sure you have valid expression with balanced paranthesis : ";	
	}
}
