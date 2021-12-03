#include<iostream>
#include<cstdlib>
using namespace std;

class Stack
{
    private:
        struct node
        {
            int data;
            node* next;
        };
        node* headNode;
    
    public:
        Stack();
        ~Stack();
        void print();
        void reversePrint();
        void push(int val);
        void pop();
        bool isEmpty();
        void Top();
};
Stack::Stack()
{
    headNode = NULL;
}

Stack::~Stack()
{
    node* ptrPrev;
    while(headNode != NULL)
    {
        ptrPrev = headNode;
        headNode = headNode->next;
        delete ptrPrev;
    }
}

void Stack::print()
{
    node* tempNode = headNode;

    cout << "Forward: ";
    while(tempNode != NULL)
    {
        cout << tempNode->data << " ";
        tempNode = tempNode->next;
    }
    cout << endl;
}
void Stack::reversePrint()
{
    node* tempNode = headNode;
    node* tempNode1 = headNode;
    int *reversePrint;
    int size = 0;
    while (tempNode->next != NULL)  
    {
        size++;
        tempNode = tempNode->next;
    }

    reversePrint = new int[size];
    int it = -1;
    while(tempNode1 != NULL)
    {
        it++;
        reversePrint[it] = tempNode1->data;
        
        tempNode1 = tempNode1->next;
    }

    cout << "Reverse: ";
    for(int i = size; i>=0; i--)
    {
        cout << reversePrint[i] << " ";
    }
    cout << endl;
}

void Stack::push(int val)
{
    node* newNode = new node;
    newNode->data = val;
    newNode->next = NULL;

    if(headNode == NULL)
    {
        headNode = newNode;
        return;
    }
    newNode->next = headNode;
    headNode = newNode;
    
    cout << "Pushing: " << headNode->data << endl;
    print();
}

void Stack::pop()
{
    node* tempNode = headNode;
    Top();
    headNode = headNode->next;
    delete tempNode;
}

bool Stack::isEmpty()
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

void Stack::Top()
{
    if(isEmpty())
    {
        cout << "List is Empty" << endl;
        return;
    }
    else
    {
        cout << "Deleting: " << headNode->data << endl;
    }
}

int main()
{
    Stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.reversePrint();
    stack.pop();
    stack.pop();
    stack.print();

    return 0;
}