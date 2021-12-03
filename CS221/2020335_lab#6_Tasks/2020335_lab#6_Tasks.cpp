/////////////////////////////////////
//NAME: MUHAMMAD OMER BIN ATIQUE
//REG NO: 2020335
//SECTION: C
//BATCH: 30
//LAB#6 INSERTION SORT HOMETASKS
/////////////////////////////////////

#include<iostream>
using namespace std;

class Students
{
    private:
        struct node
        {
            string name;
            int regNo;
            node* next;
        };
        node* headNode;
    
    public:
        Students();
        ~Students();
        void insert(string n, int r);
        void sortByReg();
        void sortByName();
        void print();
};

Students::Students()
{
    headNode = NULL;
}

Students::~Students()
{
    node* tempNode = new node;

    while(headNode == NULL)
    {
        tempNode = headNode;
        headNode = headNode->next;
        delete tempNode;
    }
}

void Students::insert(string n, int r)
{
    node* newNode = new node;

    newNode->name = n;
    newNode->regNo = r;
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

void Students::print()
{
    node* tempNode = headNode;
    int index = 1;

    cout << "\nStudents Details: \n";
    while(tempNode != NULL)
    {
        cout << "Student No#" << index << ": \n";
        cout << "Name: " << tempNode->name << endl;
        cout << "Reg No: " << tempNode->regNo << endl << endl;
        index++;
        tempNode = tempNode->next;
    }
    cout << "\n";
}

void Students::sortByName()
{
    node* sortedList = NULL;
    node* curNode = headNode;
    node* tempNode;
    node* nextNode;
    while(curNode != NULL)
    {
        nextNode = curNode->next;
        if(sortedList == NULL || (sortedList->name > curNode->name))
        {
            curNode->next = sortedList;
            sortedList = curNode;
        }   
        else
        {
            tempNode = headNode;
            while(tempNode->next!= NULL && tempNode->next->name <= curNode->name)
                tempNode = tempNode->next;
            curNode->next = tempNode->next;
            tempNode->next = curNode;
        }
        
        curNode = nextNode;
    }
    headNode = sortedList;
}

void Students::sortByReg()
{
    node* sortedList = NULL;
    node* curNode = headNode;
    node* tempNode;
    node* nextNode;
    while(curNode != NULL)
    {
        nextNode = curNode->next;
        if(sortedList == NULL || (sortedList->regNo > curNode->regNo))
        {
            curNode->next = sortedList;
            sortedList = curNode;
        }   
        else
        {
            tempNode = headNode;
            while(tempNode->next!= NULL && tempNode->next->regNo <= curNode->regNo)
                tempNode = tempNode->next;
            curNode->next = tempNode->next;
            tempNode->next = curNode;
        }
        
        curNode = nextNode;
    }
    headNode = sortedList;   
}

int main()
{
    Students studentList;
    int choice;
    string stu_name;
    int reg;
    while(true)
    {
        cout << "\nChose one of the following Choices: \n";
        cout << "1) Add a student in list.\n";
        cout << "2) Sort by Name.\n";
        cout << "3) Sort by reg.\n";
        cout << "4) Print the list.\n";
        cout << "5) Exit.\n";
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
                studentList.insert(stu_name, reg);
                break;

            case 2:
                cout << "\nList before Sorting: \n";
                studentList.print();
                studentList.sortByName();
                cout << "\nList after Sorting by Name: \n";
                studentList.print();
                break;

            case 3:
                cout << "\nList before Sorting: \n";
                studentList.print();
                studentList.sortByReg();
                cout << "\nList after Sorting by Reg: \n";
                studentList.print();
                break;

            case 4:
                studentList.print();
                break;

            case 5:
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