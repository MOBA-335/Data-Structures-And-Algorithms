/////////////////////////////////////
//NAME: MUHAMMAD OMER BIN ATIQUE
//REG NO: 2020335
//SECTION: C
//BATCH: 30
//LAB#3 SINGLE-LINKED LISTS HOMETASKS
/////////////////////////////////////

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
        void insertAtTail(int val);
        void print();
        void findSpecificNode(int key);
        void deleteSpecificNode(int key);
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
        delete tempNode;
    }
}
/*THIS FUNCTION ADDS A NEW VALUE ON THE HEAD OF A LIST LIKE A STACK.*/
void linkedList::insertAthead(int val)
{
    node* newNode = new node;
    newNode->data = val;
    newNode->next = headNode;
    headNode = newNode;
}

/*THIS FUNCTION ADDS A NEW NODE ON THE TAIL OF LIST LIKE A QUEUE*/
void linkedList::insertAtTail(int val)
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

/*THIS FUNCTION PRINTS ALL THE ELEMENTS IN A LIST*/
void linkedList::print()
{
    node* tempNode = headNode;

    cout << "\nThe list is: \n";
    while(tempNode != NULL)
    {
        cout << tempNode->data << "-->";
        tempNode = tempNode->next;
    }
    cout << "NULL\n";
}

/*THIS FUNCION TELLS YOU WHETHER THE REQUIRED ELEMENT IS IN THE LIST OR NOT*/
void linkedList::findSpecificNode(int key)
{
    node* tempNode = headNode;

    cout << "\nFinding Node...\n";

    while(tempNode != NULL && tempNode->data != key)
    {
        tempNode = tempNode->next;
    }

    if(!tempNode)
    {
        cout << "\nThe Element "<< key <<" is not in the List.\n";
    }
    else if(tempNode->data == key)
    {
        cout << "\nThe Element " << key << " is in the List.\n";
        
    }
}

/*THIS FUNCTION DELETES THE REQUIRED NODE*/
void linkedList::deleteSpecificNode(int key)
{
    node* currentNode = headNode;
    node* prevNode = currentNode;

    while(currentNode != NULL && currentNode->data != key)
    {
        prevNode = currentNode;
        currentNode = currentNode->next;
    }

    node* tempNode = new node;

    if(currentNode == NULL)
    {
        cout << "\nThe required element is not in the list.\n";
        return;
    }
    else if(currentNode->data == key)
    {
        cout << "\nDeleting node...\n";
        tempNode = currentNode;
        currentNode = currentNode->next;
        prevNode->next = currentNode;
        delete tempNode;
        cout << "\nDeletion Successful...\n";
    }
}

int main()
{
    linkedList list;

    list.insertAthead(1);
    list.insertAtTail(2);
    list.insertAthead(3);
    list.insertAtTail(4);
    list.insertAthead(5);
    list.insertAtTail(6);
    list.insertAthead(7);
    list.insertAtTail(8);
    list.print();
    list.findSpecificNode(5);
    list.findSpecificNode(3);
    list.findSpecificNode(9);
    list.deleteSpecificNode(4);
    list.print();
    list.deleteSpecificNode(2);
    list.print();
    list.deleteSpecificNode(10);
    list.print();

    return 0;
}