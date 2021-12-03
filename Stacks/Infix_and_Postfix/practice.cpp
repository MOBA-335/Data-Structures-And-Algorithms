#include<iostream>
using namespace std;

class reverse
{
    private:
        struct node
        {
            char data;
            node* next;
        };
        node* headNode;
    
    public:
        reverse();
        ~reverse();
        void Push();
        void Pop();
        void reverseList();
        void print();
        bool isEmpty();
};

reverse::reverse()
{
    headNode = NULL;
}

void reverse::Push()
{
    node* newNode;
    
}



int main()
{


    return 0;
}