#include<iostream>
using namespace std;

class Queues
{
    private:
        struct node
        {
            int data;
            node* next;
        };
        node* headNode;
        node* tailNode;

    public:
        Queues();
        ~Queues();
        bool isEmpty();
        void Enqueue(int val);
        void Dequeue();
        int front();
        void makeEmpty();
};

Queues::Queues()
{
    headNode = NULL;
    tailNode = NULL;
}
Queues::~Queues()
{
    node* tempNode = new node;

    while (tempNode != NULL)
    {
        tempNode = headNode;
        headNode = headNode->next;
        delete tempNode;
    }
}

void Queues::makeEmpty()
{
    node* tempNode = new node;

    while (tempNode != NULL)
    {
        tempNode = headNode;
        headNode = headNode->next;
        delete tempNode;
    }
}

int Queues::front()
{
    return headNode->data;
}

bool Queues::isEmpty()
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

void Queues::Enqueue(int val)
{
    node* newNode = new node;

    newNode->data = val;
    cout << "\nEnqueuing :" << newNode->data << endl;
    newNode->next = headNode;
    if(headNode==NULL)
    {
        headNode = newNode;
        tailNode = newNode;
    }
    else
    {
        tailNode->next = newNode;
        tailNode = newNode;
    }
}

void Queues::Dequeue()
{
    node* curNode = headNode;

    if(isEmpty())
    {
        cout << "\nThis List is Empty.\n" << endl;
    }
    else
    {
        
        headNode = headNode->next;
        cout << "\nDequeuing: " << curNode->data << endl; 
        delete curNode;
    }
}
//code block from lab task
/*for(int i = 0; i < size; i++)
    {
        if(array[i] == '('|| array[i] == '{' || array[i] == '[')
            queue.enqueue(array[i]);
        else if(array[i] == ')' || array[i] == '}'|| array[i] == ']')
        {
            if(queue.isEmpty() || !queue.vibeCheck(queue.queueArray[queue.rear], array[i]))
                cout << "Not Balanced" << endl;
            else 
                queue.dequeue();
        }
    }*/
int main()
{
    


    return 0;
}