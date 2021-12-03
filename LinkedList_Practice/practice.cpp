#include<iostream>
using namespace std;

class linkedList
{
    public:
        struct node 
        {
            int data;
            node* next;
        };
        node* headNode;

    public:
        linkedList()
        {
            headNode = NULL;
        }
        ~linkedList()
        {

        }
        void addAtTail(int value)
        {
            node* newNode = new node;
            newNode->data = value;
            newNode->next = NULL;

            if(headNode == NULL)
            {
                headNode = newNode;
            } 

            node* tempNode = new node;

            tempNode = headNode;

            while(tempNode->next != NULL)
                tempNode = tempNode->next;

            tempNode->next = newNode;
        }
        void print(node* tempNode)
        {
            if(tempNode == NULL)
            {
                return;
            }
            cout << tempNode->data << " ";
            print(tempNode->next);
        }
        void reverseprint(node* tempNode)
        {
            if(tempNode == NULL)
            {
                return;
            }
            reverseprint(tempNode->next);
            cout << tempNode->data << " ";
        }
};

int main()
{
    linkedList b1;

    b1.addAtTail(10);
    b1.addAtTail(20);
    b1.addAtTail(30);
    b1.addAtTail(40);
    b1.print(b1.headNode);
    cout << endl;
    b1.reverseprint(b1.headNode);

    return 0;
}