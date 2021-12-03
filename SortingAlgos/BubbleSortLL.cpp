#include<iostream>
using namespace std;

class linkedList
{
    private:
        struct node
        {
            int data;
            node* next;
        };
        node* headNode;

    public:
        linkedList();
        ~linkedList();
        void insertAthead(int val);
        void bubbleSort();
        void print();
};

linkedList::linkedList()
{
    headNode = NULL;
}
linkedList::~linkedList()
{
    node* tempNode = new node;
    
    while(headNode != NULL)
    {
        tempNode = headNode;
        headNode = headNode->next;
        delete  tempNode;
    }
}
void linkedList::insertAthead(int val)
{
    node* newNode = new node;

    newNode->data = val;
    newNode->next = NULL;

    if(headNode == NULL)
    {
        headNode = newNode;
        return;
    }

    node* tempNode = headNode;

    while(tempNode->next != NULL)
        tempNode = tempNode->next;

    tempNode->next = newNode;
}

void linkedList::bubbleSort()
{
    node* currentNode = headNode;
    node* tempNode;
    int temp;

    while(currentNode != NULL)
    {
        tempNode = headNode;
        while(tempNode != NULL)
        {
            if(currentNode->data < tempNode->data)
            {
                temp = currentNode->data;
                currentNode->data = tempNode->data;
                tempNode->data = temp;
            }
            tempNode = tempNode->next;
        }
        currentNode = currentNode->next;
    }
}

void linkedList::print()
{
    node* tempNode = headNode;

    cout << "\n";
    while(tempNode != NULL)
    {
        cout << tempNode->data << "-->";
        tempNode = tempNode->next;
    }
    cout << "NULL\n";
}
int main()
{
    linkedList list;

    list.insertAthead(34);
    list.insertAthead(44);
    list.insertAthead(3);
    list.insertAthead(87);
    list.insertAthead(22);
    list.insertAthead(2);
    list.insertAthead(23);
    list.insertAthead(7);
    list.insertAthead(17);
    list.insertAthead(89);
    list.insertAthead(66);
    cout << "\nList Before Bubble sort: ";
    list.print();
    cout << "\n";
    
    cout << "\nList After Bubble sort: ";
    list.bubbleSort();
    list.print();
    cout << "\n";


    return 0;
}