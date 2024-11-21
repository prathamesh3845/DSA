#include <iostream>
#include <cstring>  
using namespace std;

class stack {
    int *A;
    int top, size;
public:
    stack(int n = 5) {
        A = new int[n];
        if (!A) return;
        top = -1;
        size = n;
    }
    
    int isfull() {
        return top == size - 1;
    }
    
    int isempty() {
        return top == -1;
    }
    
    void push(int ele) {
        if (isfull()) 
            return;  
        A[++top] = ele;
    }
    
    int pop() {
        if (isempty()) 
            return -1;  
        return A[top--];
    }
};

int isDigit(char c) {
    return (c >= '0' && c <= '9');
}

int isoperator(char opr) {
    return (opr == '+' || opr == '-' || opr == 'x' || opr == '/');
}

int eval(int a, int b, char opr) {
    switch(opr) {
        case '+': return a + b;
        case '-': return a - b;
        case 'x': return a * b;
        case '/': return a / b;
        default: return 0;
    }
}

int main(int argc, char **argv) {
    stack s1(10);
    int n = 0, R, op1, op2;
    char op;

    for (int i = 1; i < argc; i++) {
        if (isDigit(argv[i][0])) {
            n = 0;
            for (int j = 0; j < strlen(argv[i]); j++) {
                n = n * 10 + (argv[i][j] - '0');
            }
            s1.push(n);
        } 
        else if (isoperator(argv[i][0])) {
            if (s1.isempty()) {
                cout << "Error: Not enough operands for operator " << argv[i][0] << endl;
                return -1;
            }
            op2 = s1.pop();
            
            if (s1.isempty()) {
                cout << "Error: Not enough operands for operator " << argv[i][0] << endl;
                return -1;
            }
            op1 = s1.pop();
            s1.push(eval(op1, op2, argv[i][0]));
        }
    }
    if (!s1.isempty()) {
        cout << "Result: " << s1.pop() << endl;
    } else {
        cout << "Error: The stack is empty, no result." << endl;
    }

    return 0;
}
