#include<iostream>
using namespace std;

class postfix
{
    public:
        struct node
        {
            char data;
            node* next;
        };
        node* headNode;

    public:
        postfix();
        ~postfix();
        void push(char c);
        void pop();
        bool isEmpty();
        bool isOperand(char &);
        bool isOperator(char &);
        bool isLeftParantheses(char );
        bool isRightParantheses(char &);
        bool higherPrecedence(char &, char);
        char top();
};

postfix::postfix()
{
    headNode = NULL;
}

postfix::~postfix()
{
    node* ptrprev;
    while(headNode != NULL)
    {
        ptrprev = headNode;
        headNode = headNode->next;
        delete ptrprev;
    }
}

void postfix::push(char val)
{
    node* newNode = new node;
    newNode->data = val;
    newNode->next = headNode;
    headNode = newNode;
}

void postfix::pop()
{
    node* tempNode = headNode;
    headNode = headNode->next;
    delete tempNode;
}

bool postfix::isEmpty()
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

char postfix::top()
{
    return headNode->data;
}

bool postfix::isOperand(char &c)
{
    if(c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9'|| c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e')
    {
        return true;
    }
    else 
    {
        return false;
    }
}
bool postfix::isOperator(char &c)
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

bool postfix::isLeftParantheses(char c)
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

bool postfix::isRightParantheses(char &c)
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

bool postfix::higherPrecedence(char &q, char s)
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

int main()
{
    char Q[100];
    char P[100];
    postfix S;
    int i = 0;
    int j = 0;
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

    cout << "Infix: ";
    for(int i = 0; i<=size; i++)
    {
        cout << Q[i] << " ";
    
    }

    cout << "\n";
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
        cout << P[i] << " ";
    }
    cout << "\n";

    return 0;
}