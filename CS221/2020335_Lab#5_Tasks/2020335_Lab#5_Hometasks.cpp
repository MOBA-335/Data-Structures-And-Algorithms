/////////////////////////////////////
//NAME: MUHAMMAD OMER BIN ATIQUE
//REG NO: 2020335
//SECTION: C
//BATCH: 30
//LAB#5 QUEUE HOMETASKS
/////////////////////////////////////

#include<iostream>
#include<string.h>
using namespace std;

class queues
{
    public:
       char *queueArray;
       int Size;
       int front;
       int rear;
       int numOfItems;
       char item;
    
    public:
        queues(){}
        queues(int);
        ~queues();
        void enqueue(int);
        void dequeue();
        bool isEmpty();
        bool isFull();
        void clear();
        bool vibeCheck(char opening, char closing);
};

queues::queues(int size)
{
    queueArray = new char[size];
    Size = size;
    front = -1;
    rear = -1;
    numOfItems = 0;
}

queues::~queues()
{
    delete [] queueArray;
}

void queues::enqueue(int val)
{
    if(isFull())
    {
            cout << "\nThe queue is full.\n";
    }
    else
    {
        rear = (rear + 1) % Size;
        queueArray[rear] = val;
        numOfItems++;
    }
}

void queues::dequeue()
{
    if(isEmpty())
    {
        cout << "The queue is empty.\n";
    }
    else
    {
        front = (front + 1) % Size;
        item = queueArray[front];
        rear--;
        numOfItems--;
        
    }
}

bool queues::isEmpty()
{
    if(numOfItems)
        return false;
    else
        return true;
}

bool queues::isFull()
{
    if(numOfItems < Size)
        return false;
    else
        return true;
}

void queues::clear()
{
    front = -1;
    rear = -1;
    numOfItems = 0;
}

bool queues::vibeCheck(char opening, char closing)
{
    if(opening == '(' && closing == ')')
        return true; 
    else if(opening == '{' && closing == '}')
        return true;
    else if(opening == '[' && closing == ']')
        return true;
    else
        return false;
}

int main()
{
    char array[51];
    queues queue(10);
    bool check = true;
    cout << "\nEnter an Expression: ";
    gets(array);

    int size = strlen(array);

    //checks for expressions of the type e.g {}()[]
    for(int i = 0; i<= size; i++)
    {
        if(array[i] == '('|| array[i] == '{' || array[i] == '[')
        {
            if(queue.vibeCheck(array[i], array[i+1]))
            {
                check = true;
            }
            else
            {
                check = false;
                break;
            }
        }
    }

    //checks for expressions of the type starting with  ), ] or }
    if(array[0] == ')' || array[0] == '}'|| array[0] == ']')
    {
        cout << "Not Balanced.\n";
        return 0;
    }

    //checks for expressions of the type e.g {([])}
    for(int i = 0; i <= size; i++)
    {
        if(array[i] == '('|| array[i] == '{' || array[i] == '[')
            queue.enqueue(array[i]);
    }
    for(int i = 0; i < size; i++)
    {
        if(array[i] == ')' || array[i] == '}'|| array[i] == ']')
        {
            if(queue.isEmpty() || !queue.vibeCheck(queue.queueArray[queue.rear], array[i]))
                continue;
            else 
                queue.dequeue();
        }
    }

    

    if(queue.isEmpty() || check)
        cout << "Balanced.\n";
    else
        cout << "Not Balanced.\n";

    return 0;
}