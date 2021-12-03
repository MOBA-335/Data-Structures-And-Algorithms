//*******************************
//Name: Muhammad Omer BIn Attique
//Reg No: 2020335
//Subject:CS221
//Section:C
//Assignment No:2
//*******************************

#include<iostream>
using namespace std;

class linkedList
{
    public:
        struct node
        {
            char data;
            node* next;
        };
        node* headNode;

    public:
        linkedList();
        ~linkedList();
        void push(char c);
        void pop();
        bool isEmpty();
        bool isOperand(char &);
        bool isOperator(char &);
        bool isLeftParantheses(char );
        bool isRightParantheses(char &);
        bool higherPrecedence(char &, char);
        char top();
        int applyOp(int , int , char );
        int precedence(char );
        bool headNext();
        int evaluation(char *Q, int size);
        void infixToPostfix(char *Q, int size);
};

linkedList::linkedList()
{
    headNode = NULL;
}

linkedList::~linkedList()
{
    node* ptrprev;
    while(headNode != NULL)
    {
        ptrprev = headNode;
        headNode = headNode->next;
        delete ptrprev;
    }
}

int linkedList::applyOp(int a, int b, char op)
{
    switch(op)
    {
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
        case '/':
            return a/b;
        default:
            return 0;
    }
}
int linkedList::precedence(char op)
{
    if(op == '+' || op == '-')
        return 1;
    if(op == '*' || op == '/')
        return 2;
    return 0;
}
void linkedList::push(char val)
{
    node* newNode = new node;
    newNode->data = val;
    newNode->next = headNode;
    headNode = newNode;
}

void linkedList::pop()
{
    node* tempNode = headNode;
    headNode = headNode->next;
    delete tempNode;
}

bool linkedList::isEmpty()
{
    if(headNode == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

char linkedList::top()
{
    return headNode->data;
}

bool linkedList::headNext()
{
    if(headNode->next == NULL)
        return true;
    else
        return false;
}
bool linkedList::isOperand(char &c)
{
    if(c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9'|| c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e')
    {
        return true;
    }
    else 
    {
        return false;
    }
}
bool linkedList::isOperator(char &c)
{
    if(c == '+' || c == '-' || c == '*' || c== '/' || c== '^')
    {
        return true;
    }
    else 
    {
        return 0;
    }
}

bool linkedList::isLeftParantheses(char c)
{
    if(c == '{' || c== '[' || c == '(')
    {
        return true;
    }
    else
    {
        return 0;
    }
}

bool linkedList::isRightParantheses(char &c)
{
    if(c == '}' || c == ']' || c == ')')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool linkedList::higherPrecedence(char &q, char s)
{
    if(q == '+' && (s== '+' || s == '-' || s == '*' || s == '/' || s == '^'))
    {
        return true;
    }
    else if(q == '-' && (s == '-' || s == '*' || s == '/' || s == '^'))
    {
        return true;
    }
    else if(q == '*' && (s == '*' || s == '/' || s == '^'))
    {
        return true;
    }
    else if(q == '/' && (s == '/' || s == '^'))
    {
        return true;
    }
    else if(q == '^' && s == '^')
    {
        return true;
    }
    else 
    {
        return false;
    }
}

int linkedList::evaluation(char *Q, int size)
{
    linkedList value;
    linkedList operators;
    int val;
    int sol = 0;
    for(int i=0; i<size; i++)
    {
        if(Q[i] == ' ')
        {
            continue;
        }
        else if(operators.isLeftParantheses(Q[i]))
        {
            operators.push(Q[i]);
        }
        else if(operators.isOperand(Q[i]))
        {
            
            val = 0;
            while(operators.isOperand(Q[i]) && i < size)
            {
                val = (val*10) + (Q[i] - '0');
                i++;
            }
            value.push(val);
        }
        else if(operators.isRightParantheses(Q[i]))
        {
            while(!operators.isEmpty() && !operators.isLeftParantheses(operators.top()))
            {
                int a = value.top();
                value.pop();
                int b = value.top();
                value.pop();

                char op = operators.top();
                operators.pop();

                sol = operators.applyOp(a, b, op);
                value.push(operators.applyOp(a, b, op));
            }

            if(!operators.isEmpty())
                operators.pop();
        }
        else
        {
            while(!operators.isEmpty() && operators.precedence(operators.top()) >= operators.precedence(Q[i]))
            {
                if(operators.headNext())
                    break;
                int a = value.top();
                value.pop();
                int b = value.top();
                value.pop();

                char op = operators.top();
                operators.pop();

                sol = operators.applyOp(a, b, op);
                value.push(operators.applyOp(a, b, op));
            }

            operators.push(Q[i]);
        }
    }

    while(!operators.isEmpty())
    {
        int a = value.top();
        value.pop();
        int b = value.top();
        value.pop();

        char op = operators.top();
        operators.pop();

        sol = operators.applyOp(a, b, op);
        value.push(operators.applyOp(a, b, op));
    }

    return sol;
}

void linkedList::infixToPostfix(char *Q, int size)
{
    char P[100];
    linkedList S;
    int i = 0;
    int j = 0;
    S.push('(');
    Q[size] = ')';
    Q[size+1] = '\0'; 
    while(!S.isEmpty())
    {
        if(S.isOperand(Q[i]))
        {
            P[j] = Q[i];
            j++;
        }
        else if(S.isLeftParantheses(Q[i]))
        {
            S.push(Q[i]);
        }
        else if(S.isOperator(Q[i]))
        {
            while(S.higherPrecedence(Q[i], S.top()))
            {
                if(S.top() == '(' || S.top() == '{'||S.top() == '[')
                {
                    break;
                }
                P[j] = S.top();
                j++;
                S.pop();
            }
            S.push(Q[i]);
        }
        else if(S.isRightParantheses(Q[i]))
        {
            while(!(S.isLeftParantheses(S.top())))
            {
                P[j] = S.top();
                j++;
                S.pop();
            }
            S.pop();
        }
        i++;
    }

    P[j] = '\0';

    cout << "Postfix: ";
    for(int i = 0; i<=j; i++)
    {
        cout << P[i];
    }
    cout << "\n";
}

int main()
{
    char Q[100];
    linkedList expression;
    int size;
    
    cout << "Enter the infix expression: ";
    gets(Q);

    for(int i = 0; i<100; i++)
    {
        if(Q[i] == '\0')
        {
            size = i;
            break;
        }
    }
    
    cout << "\n //////////-------|IMPORTANT NOTE|-------//////////\n";
    cout << "Enter Each number and character with space in between.\n";
    cout << "Infix: ";
    for(int i = 0; i<=size; i++)
    {
        cout << Q[i];
    }
    cout << "\n\n";

    //Infix to Postfix implementaiton 
    expression.infixToPostfix(Q, size);

    //Expression Evaluation Implementation
    int solution = expression.evaluation(Q, size);

    cout << "The Solution of the expression ";
    for(int i = 0; i<=size - 1; i++)
    {
        cout << Q[i];
    
    }
    cout << ": " << solution << endl;

    return 0;
}