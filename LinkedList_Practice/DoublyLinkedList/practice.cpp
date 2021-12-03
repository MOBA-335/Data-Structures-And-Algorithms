#include<iostream>
using namespace std;
class doublyList
{
    private:
        struct node
        {
            int data;
            node* prev;
            node* next;
        };
        node* headNode;

    public:
    doublyList();
    ~doublyList();
    void insertAtHead(int val);
    void insertAtTail(int val);
    void print();
    void reversePrint();
};

doublyList::doublyList()
{
    headNode = NULL;
}

doublyList::~doublyList()
{
    node* ptrPrev;
    while(headNode != NULL)
    {
        ptrPrev = headNode;
        headNode = headNode->next;
        delete ptrPrev;
    }
}

void doublyList::insertAtHead(int val)
{
    node* newNode = new node;

    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;

    if(headNode == NULL)
    {
        headNode = newNode;
        return;
    }

    headNode->prev = newNode;
    newNode->next = headNode;
    headNode = newNode;

}

void doublyList::insertAtTail(int val)
{
    node* tempNode = headNode;
    node* newNode = new node;

    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;

    if(headNode==NULL)
    {
        headNode = newNode;
        return;
    } 

    while(tempNode->next == NULL)
        tempNode = tempNode->next;
    
    tempNode->next = newNode;
    newNode->prev = tempNode;
    
}

void doublyList::print()
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

void doublyList::reversePrint()
{
    node* tempNode = headNode;
    if(tempNode == NULL)
        return;

    while(tempNode != NULL)
    {
        tempNode = tempNode->next;
    }

    cout << "Reverse: ";
    while(tempNode->prev != NULL)
    {
        cout << tempNode->data << " ";
        tempNode = tempNode->next;
    }
    cout << endl;
}

int main()
{
    doublyList b1;

    b1.insertAtTail(10);
    b1.insertAtTail(11);
    b1.insertAtTail(20);
    b1.insertAtTail(30);
    b1.print();
    b1.reversePrint();

    return 0;
}