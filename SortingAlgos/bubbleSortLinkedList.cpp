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
        void insert(int val);
        void bubbleSort();
        void print();
};

linkedList::linkedList()
{
    headNode = NULL;
}

linkedList::~linkedList()
{
    node* tempNode;

    while(headNode != NULL)
    {
        tempNode = headNode;
        headNode = headNode->next;
        delete tempNode;
    }
}

void linkedList::insert(int val)
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

void linkedList::print()
{
    node* tempNode = headNode;

    while(tempNode != NULL)
    {
        cout <<  tempNode->data << "->";
        tempNode = tempNode->next;
    }
    cout << "NULL\n";
}

void linkedList::bubbleSort()
{
    node* curNode = headNode;
    node* nextNode;

    while(curNode != NULL)
    {
        
        while(curNode != NULL || curNode->next != NULL)
        {
            nextNode = curNode->next;
            if(nextNode == NULL)
            {
                break;
            }
            if(curNode->data > nextNode->data)
            {
                if(curNode == headNode)
                {
                    curNode->next = nextNode->next;
                    nextNode->next = curNode;
                    headNode = nextNode;

                }
                else
                {
                    curNode->next = nextNode->next;
                    nextNode->next = curNode;
                }
                
            }
            curNode = curNode->next;
            if(curNode == NULL)
            {
                curNode = headNode;
                break;
            }
        }
        if(nextNode == NULL)
        {
            break;
        }
    }
}

int main()
{
    linkedList list;

    list.insert(3);
    list.insert(2);
    list.insert(6);
    list.insert(5);
    list.insert(4);
    list.insert(8);

    cout << "\nBefore Sorting: ";
    list.print();

    list.bubbleSort();

    cout << "\nAfter Sorting: ";
    list.print();

    return 0;
}