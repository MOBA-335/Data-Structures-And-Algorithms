/////////////////////////////////////
//NAME: MUHAMMAD OMER BIN ATIQUE
//REG NO: 2020335
//SECTION: C
//BATCH: 30
//LAB#4 DOUBLY-LINKED LISTS HOMETASKS
/////////////////////////////////////

#include<iostream>
using namespace std;

class doublyLinkedList
{
    private:
        struct node
        {
            string name;
            int reg_no;
            node* next;
            node* prev;
        };
        node* headNode;
        node* tailNode;

    public: 
        doublyLinkedList();
        ~doublyLinkedList();
        void insertAtStartOfList(string n, int r);
        void insertAtTail(string n,int r);
        void insertInMiddle(string key, string n, int r);
        void deleteAll();
        void deleteSpecificStudent(string key);
        void find(string key);
        void showAll();
};

doublyLinkedList::doublyLinkedList()
{
    headNode = NULL;
    tailNode = NULL;
}

doublyLinkedList::~doublyLinkedList()
{
    node* tempNode = new node;

    while(headNode != NULL)
    {
        tempNode = headNode;
        headNode = headNode->next;
        delete tempNode;
    }
}

void doublyLinkedList::insertAtStartOfList(string n, int r)
{
    node* newNode = new node;
    
    newNode->name = n;
    newNode->reg_no = r;
    newNode->next = headNode;
    newNode->prev = NULL;
    if(headNode == NULL)
    {
        headNode = newNode;
        tailNode = newNode;
        return;
    }
    headNode->prev = newNode;
    headNode = newNode;

}

void doublyLinkedList::insertAtTail(string n, int r)
{
    node* newNode = new node;

    newNode->name = n;
    newNode->reg_no = r;
    newNode->next = NULL;
    newNode->prev = NULL;


    if(headNode == NULL)
    {
        headNode = newNode;
        tailNode = newNode;
        return;
    }
    
    tailNode->next = newNode;
    newNode->prev = tailNode;
    tailNode = newNode;
}

void doublyLinkedList::insertInMiddle(string key, string n, int r)
{
    cout << "\nAdding Node at desired position...\n";

    node* newNode = new node;
    newNode->name = n;
    newNode->reg_no = r;
    newNode->next = NULL;
    newNode->prev = NULL;

    node* tempNode = headNode;
    node* nextNode = tempNode->next;
    while(tempNode->name != key)
    {
        if(tempNode == NULL)
        {   
            cout << "\nThe student after which you want to add this student is not in the list.\n";
            return;
        }
        tempNode = tempNode->next;
        nextNode = tempNode->next;
    }
    if(tempNode== tailNode)
    {
        insertAtTail(n, r);
        return;
    }
    tempNode->next = newNode;
    newNode->next = nextNode;
    newNode->prev = tempNode;
    nextNode->prev = newNode;
}

void doublyLinkedList::find(string key)
{
    if(headNode == NULL)
    {
        cout << "\nList is Empty\n";
        return;
    }
    else
    {
        node* tempNode = headNode;

        while(tempNode->name != key)
        {
            if(tempNode == NULL)
            {
                cout << "\nReqired Student is not in list.\n";
                return;
            }
            tempNode= tempNode->next;
        }

        cout << "\nThe Student is in the List.\nHere are the student details: \n";
        cout << "Name: " << tempNode->name << endl;
        cout << "Reg No: " << tempNode->reg_no << endl;
    }
}

void doublyLinkedList::showAll()
{
    if(headNode == NULL)
    {
        cout << "\nList is Empty\n";
        return;
    }
    else
    {
        node* tempNode = headNode;
        int i = 1;
        while(tempNode != NULL)
        {
            cout << "\nHere are the details for student " << i << " : \n";
            cout << "Name: " << tempNode->name << endl;
            cout << "Reg No: " << tempNode->reg_no << endl << endl;
            tempNode = tempNode->next;
            i++;
        }
    }
}

void doublyLinkedList::deleteAll()
{
    node* tempNode = new node;

    cout << "\nDeleting The Data Base...\n";

    while(headNode != NULL)
    {
        tempNode = headNode;
        headNode = headNode->next;
        delete tempNode;
    }
    headNode = NULL;
    cout << "\nDeletion Successful...\n";
}

void doublyLinkedList::deleteSpecificStudent(string key)
{
    if(headNode == NULL)
    {
        cout << "\nThe List is Empty.\n";
        return;
    }
    else
    {
        node* curNode = headNode;
        node* prevNode;

        cout << "\nDeleting Node...\n";

        while(curNode->name != key)
        {
            prevNode = curNode;
            curNode = curNode->next;
        }
        if(curNode== headNode)
        {
            node* tempNode = headNode;
            headNode = headNode->next;
            delete tempNode;
            cout << "\nDeletion Successful...\n";
            return;
        }
        if(curNode == tailNode)
        {
            node* tempNode = tailNode;
            tailNode = tailNode->prev;
            delete tempNode;
            tailNode->next = NULL;
            cout << "\nDeletion Successful...\n";
            return;
        }
        node* tempNode = curNode;
        prevNode->next = curNode->next;
        curNode = curNode->next;
        curNode->prev = prevNode;
        delete tempNode;

        cout << "\nDeletion Successful...\n";
    }
}

int main()
{
    doublyLinkedList studentList;
    int choice, reg;
    string stu_name, stu;

    while(true)
    {
        cout << "\nChose one of the following Choices: \n";
        cout << "1) Add a student at start of list.\n";
        cout << "2) Add a student at the end of list.\n";
        cout << "3) Add a student between the nodes.\n";
        cout << "4) Show all students.\n";
        cout << "5) Find a student.\n";
        cout << "6) Remove a student.\n";
        cout << "7) Remove all students.\n";
        cout << "8) Exit Program.\n";
        cout << "Your Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "\nEnter Student Details: \n";
                cout << "Enter Student Name: ";
                cin >> stu_name;
                cout << "Enter Student Reg No: ";
                cin >> reg;
                studentList.insertAtStartOfList(stu_name, reg);
                break;

            case 2:
                cout << "\nEnter Student Details: \n";
                cout << "Enter Student Name: ";
                cin >> stu_name;
                cout << "Enter Student Reg No: ";
                cin >> reg;
                studentList.insertAtTail(stu_name, reg);
                break;

            case 3:
                cout << "\nEnter Student Details: \n";
                cout << "Enter Student Name: ";
                cin >> stu_name;
                cout << "Enter Student Reg No: ";
                cin >> reg;
                cout << "Enter After which student you want to add the new student: ";
                cin >> stu;
                studentList.insertInMiddle(stu, stu_name, reg);
                break;

            case 4:
                studentList.showAll();
                break;

            case 5:
                cout << "\nWhich student do you want to find? Enter Name: ";
                cin >> stu_name;
                studentList.find(stu_name);
                break;
            
            case 6:
                cout << "\nWhich student do you want to delete from List? Enter Name: ";
                cin >> stu_name;
                studentList.deleteSpecificStudent(stu_name);
                break;
                
            case 7:
                studentList.deleteAll();
                break;

            case 8:
                cout << "\nTHANK YOU. HAVE A NICE DAY. :)\n";
                return 0;
                break;

            default:
                cout << "\nINVALID INPUT.\nPLEASE TRY AGAIN\n";
                break;
        }

    }
}