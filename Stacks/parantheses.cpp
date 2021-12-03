#include<iostream>
#include<stack>
#include<string.h>
using namespace std;

class list
{
    private:
        struct node
        {
            char data;
            node* next;
        };
        node* headNode;

    public:
        list();
        ~list();
        void push(char val);
        void pop();
        bool vibeCheck(char opening, char closing);
        bool isEmpty();
        char top();
};

list::list()
{
    headNode = NULL;
}

list::~list()
{
    node* ptrPrev;
    while(headNode != NULL)
    {
        ptrPrev = headNode;
        headNode = headNode->next;
        delete ptrPrev;
    }
}

void list::push(char val)
{
    node* newNode = new node;
    newNode->data = val;
    newNode->next = headNode;
    headNode = newNode; 
}
void list::pop()
{
    node* tempNode = headNode;
    headNode = headNode->next;

    delete tempNode;
}
char list::top()
{
    if(isEmpty())
    {
        cout << "The list is empty." << endl;
        return '\0';
    }
    else
    {
        return headNode->data;
    }
}

bool list::isEmpty()
{
    if(headNode == NULL)
    {
        return true;
    }
    else{
        return false;
    }
}

bool list::vibeCheck(char opening, char closing)
{
    if( opening == '(' && closing == ')')
        return true; 
    else if(opening == '{' && closing == '}')
        return true;
    else if(opening == '[' && closing == ']')
        return true;
    else
        return false;
}

int main()
{
    char array[51];
    list stack;
    cout << "Enter an Expression: ";
    gets(array);

    int size = strlen(array);
    for(int i = 0; i < size; i++)
    {
        if(array[i] == '('|| array[i] == '{' || array[i] == '[')
            stack.push(array[i]);
        else if(array[i] == ')' || array[i] == '}'|| array[i] == ']')
        {
            if(stack.isEmpty() || !stack.vibeCheck(stack.top(), array[i]))
                cout << "Not Balanced" << endl;
            else 
                stack.pop();
        }
    }
    
    if(stack.isEmpty())
        cout << "Balancecd.\n";
    else
        cout << "Not Balanced.\n";
        

    return 0;
}