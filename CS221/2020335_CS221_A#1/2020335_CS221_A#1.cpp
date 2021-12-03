/////////////////////////////////////
//NAME: MUHAMMAD OMER BIN ATIQUE
//REG NO: 2020335
//SECTION: C
//BATCH: 30
//ASSIGNMENT NO#1
/////////////////////////////////////
 
#include<iostream>
using namespace std;

class linkedList
{
    private:
        struct node
        {
            int data;
            int pos;
            node* next;
        };
        node* headNode;
        int items;
        int oddItems;

    public:
        linkedList();
        ~linkedList();
        void insertAtTail(int val);
        void insertOddAtTail(int val);
        void insertAtHead(int val);
        void print();
        void sort();
        void deleteNode(int val);
};

linkedList::linkedList()
{
    headNode = NULL;
    items = 0;
    oddItems = 1;
}

linkedList::~linkedList()
{
    node* tempNode = new node;

    while(headNode!=NULL)
    {
        tempNode = headNode;
        headNode = headNode->next;
        delete tempNode;
    }
}

void linkedList::insertAtTail(int val)
{
    node* newNode = new node;

    items++;

    newNode->data = val;
    newNode->pos = items;
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

void linkedList::insertOddAtTail(int val)
{
    node* newNode = new node;

    newNode->data = val;
    newNode->pos = oddItems;
    newNode->next = NULL;

    oddItems= oddItems+2;

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

    cout << "\n";
    while(tempNode != NULL)
    {
        cout << tempNode->data << "(" << tempNode->pos << ")"<< "-->";
        tempNode = tempNode->next;
    }
    cout << "NULL\n";
}

void linkedList::deleteNode(int val)
{
    node* currentNode = headNode;
    node* prevNode;

    while(currentNode->data != val && currentNode != NULL )
    {
        prevNode = currentNode;
        currentNode = currentNode->next;
    }

   if(currentNode == NULL)
    {
       cout << "\nThe requried Element is not present in th elist.";
       return;
    } 
    
    if(currentNode == headNode) 
    {
        headNode = headNode->next;
    }
    else
    {
        prevNode->next = currentNode->next;
    }

    delete currentNode; 
}

void linkedList::sort()
{
    node* temp = headNode;
    int sortValue;
    while(temp != NULL)
    {   
        
        if((temp->pos%2) != 0)
        {
            sortValue = temp->data;
            deleteNode(sortValue);
            insertOddAtTail(sortValue);
            temp = headNode;
        }
        else
        {
            temp = temp->next;
        }
        if(temp->pos == 1)
        {
            break;
        }
    } 
}
int main()
{
    linkedList list;
    int choice;
    int element;

    while(true)
    {
        cout << "\nChose one of the following Choices: \n";
        cout << "1) Add an element in list.\n";
        cout << "2) Sort list.\n";
        cout << "3) Print List.\n";
        cout << "4) Exit.\n";
        cout << "Your Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "\nEnter A Number: ";
                cin >> element;
                list.insertAtTail(element);
                break;

            case 2:
                cout << "\nList Before Sorting:\n";
                list.print();
                cout << "\nSorting List...\n";
                list.sort();
                
                cout << "Sorting Successful\n";
                cout << "\nList after Sorting:\n";
                list.print();
                break;

            case 3:
                cout << "\nPrinting List\n";
                list.print();
                break;

            case 4:
                cout << "\nTHANK YOU. HAVE A NICE DAY. :)\n";
                return 0;
                break;

            default:
                cout << "\nINVALID INPUT.\nPLEASE TRY AGAIN\n";
                break;
        }

    }

    return 0;
}