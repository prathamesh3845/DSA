
/*TITLE : Assignment No - 8 : Write a program 
to convert infix expression to postfix, 
to convert infix expression to prefix 
and evaluation of postfix and prefix expression.
*/

#include <iostream>
#include <string>
#define capacity 100 
using namespace std;

class Stack
{
    int arr[capacity]; 
    int top;           

public:
    Stack() { top = -1; } 

    // Function to check if stack is empty
    bool isEmpty()
    {
        return top == -1; 
    }

    // Function to check if stack is full
    bool isFull()
    {
        return top == capacity - 1; 
    }

    // Function to push an element to the stack
    void push(int n)
    {
        if (isFull())
        {
            cout << "Stack is full." << endl; 
        }
        else
        {
            top++;       
            arr[top] = n; 
        }
    }

    // Function to pop an element from the stack
    int pop()
    {
        int n;
        if (isEmpty())
        {
            cout << "Stack is Empty" << endl; 
            return 0;                         
        }
        else
        {
            n = arr[top]; 
            top--;        
        }
        return n;  // Return the popped element
    }

    // Function to get the top element without popping
    int stacktop()
    {
        if (isEmpty())
        {
            return -1; }
        else
        {
            return arr[top]; // Return the top element
        }
    }

    // Function to convert infix expression to postfix
    string infixtopostfix(string infix);

    // Function to convert infix expression to prefix
    string infixtoprefix(string exp);

    // Function to evaluate postfix expression
    int postfixevalution(string postfix);

    // Function to evaluate prefix expression
    int prefixevalution(string prefix);
};

// Function to check if a character is an operator
int isoperator(char a)
{
    if (a == '+' || a == '-' || a == '*' || a == '/')
    {
        return 1; // Return 1 if character is an operator
    }
    else
    {
        return 0; // Return 0 if character is not an operator
    }
}

// Function to determine precedence of operators
int precedence(char ch)
{
    if (ch == '/' || ch == '*')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1; 
    else
        return -1; 
}

// Function to convert infix to postfix
string Stack::infixtopostfix(string infix)
{
    string postfix = ""; // Initialize postfix string
    int i = 0;
    while (infix[i] != '\0')
    {
        if (!isoperator(infix[i]) && infix[i] != '(' && infix[i] != ')')
        {
            postfix = postfix + infix[i]; // Add operand to postfix
        }
        else if (infix[i] == '(')
        {
            push(infix[i]); // Push '(' to stack
        }
        else if (infix[i] == ')')
        {
            while (!isEmpty() && stacktop() != '(')
            {
                postfix += pop(); // Pop and add to postfix until '(' is found
            }
            pop(); // Remove '(' from stack
        }
        else
        {
            while (!isEmpty() && precedence(infix[i]) <= precedence(stacktop()))
            {
                postfix += pop(); // Pop operators with higher or equal precedence
            }
            push(infix[i]); // Push current operator to stack
        }
        i++;
    }
    while (!isEmpty())
    {
        postfix += pop(); // Pop remaining operators
    }
    return postfix;
}

// Function to reverse a string (used for prefix conversion)
string reversestring(string exp)
{
    int len = exp.size();
    char ch;
    for (int i = 0; i < len / 2; i++)
    {
        ch = exp[i];
        exp[i] = exp[len - 1 - i];
        exp[len - 1 - i] = ch;
    }
    return exp;
}

// Function to convert infix to prefix
string Stack::infixtoprefix(string exp)
{
    string infix = reversestring(exp); // Reverse the infix expression
    string prefix = "";                // Initialize prefix string
    int i = 0;
    while (exp[i] != '\0')
    {
        if (!isoperator(infix[i]) && infix[i] != ')' && infix[i] != '(')
        {
            prefix = prefix + infix[i]; // Add operand to prefix
        }
        else if (infix[i] == ')')
        {
            push(infix[i]); // Push ')' to stack
        }
        else if (infix[i] == '(')
        {
            while (!isEmpty() && stacktop() != ')')
            {
                prefix += pop(); // Pop and add to prefix until ')' is found
            }
            pop(); // Remove ')' from stack
        }
        else
        {
            while (!isEmpty() && precedence(infix[i]) < precedence(stacktop()))
            {
                prefix += pop(); // Pop operators with higher precedence
            }
            push(infix[i]); // Push current operator to stack
        }
        i++;
    }
    while (!isEmpty())
    {
        prefix += pop(); // Pop remaining operators
    }
    return reversestring(prefix); // Reverse the prefix expression before returning
}

// Function to perform operations (+, -, *, /)
int operation(int a, int b, char op)
{
    switch (op)
    {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    default:
        cout << "Invalid Operator" << endl;
        return 0;
    }
}

// Function to evaluate a postfix expression
int Stack::postfixevalution(string postfix)
{
    int i = 0;
    while (postfix[i] != '\0')
    {
        if (!isoperator(postfix[i]))
        {
            push(postfix[i] - '0'); // Push operand to stack
        }
        else
        {
            int val1 = pop(); // Pop two operands
            int val2 = pop();
            int result = operation(val2, val1, postfix[i]); // Perform operation
            push(result); // Push result to stack
        }
        i++;
    }
    if (top == -1)
        return 0;
    else
        return arr[top]; // Return final result
}

// Function to evaluate a prefix expression
int Stack::prefixevalution(string prefix)
{
    int n = prefix.size();
    int i = n - 1;
    while (i >= 0)
    {
        if (!isoperator(prefix[i]))
        {
            push(prefix[i] - '0'); // Push operand to stack
        }
        else
        {
            int val1 = pop(); // Pop two operands
            int val2 = pop();
            int result = operation(val1, val2, prefix[i]); // Perform operation
            push(result); // Push result to stack
        }
        i--;
    }

    if (top == -1)
        return 0;
    else
        return arr[top]; // Return final result
}

int main()
{
    Stack obj; 
    cout << "1 -> INFIX TO POSTFIX" << endl
         << "2 -> INFIX TO PREFIX " << endl   
         << "3 -> POSTFIX EVALUATION " << endl
         << "4 -> PREFIX EVALUATION " << endl
         << "5 -> EXIT " << endl
         << endl;

    int ch;
    do
    {
        cout << "Enter your choice : ";
        cin >> ch;
        cout << endl;
        switch (ch)
        {
        case 1:
        {
            string infix;
            cout << "Enter the infix expression : "; 
            cin >> infix;                            
            cout << "The postfix exp is : " << obj.infixtopostfix(infix) << endl << endl; 
            break;
        }
        case 2:
        {
            string infix;
            cout << "Enter the infix expression : "; 
            cin >> infix;                             
            cout << "The prefix exp is : " << obj.infixtoprefix(infix) << endl<< endl; 
            break;
        }
        case 3:
        {
            string postfix;
            cout << "Enter the postfix expression : "; 
            cin >> postfix;                           
            cout << "THE ANSWER IS: " << obj.postfixevalution(postfix) << endl << endl; 
            break;
        }
        case 4:
        {
            string prefix;
            cout << "Enter the prefix expression : "; 
            cin >> prefix;                        
            cout << "THE ANSWER IS: " << obj.prefixevalution(prefix) << endl<< endl; 
            break;
        }
        case 5:
            cout << "EXIT !!!!!!" << endl << endl; 
            break;

        default:
            cout << "Enter the correct choice......." << endl; 
        }
    } while (ch != 5); 
    return 0;
}
