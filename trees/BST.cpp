#include<iostream>
using namespace std;

class tree
{
    private:
        struct node
        {
            int data;
            node* leftNode;
            node* rightNode;
        };
        node* headNode;
    
    public:
        tree();
        ~tree();
        void insertNode(int val);
        bool searchNode(int val);
        void makeDeletion(node* &);
        void destroySubTree(node *);
        void deleteNode(int key, node* &);
        void displayInOrder(node*);
        void displayPreOrder(node*);
        void displayPostOrder(node*);
        void showNodesInOrder()
        {
            displayInOrder(headNode);
        }
        void showNodesPreOrder()
        {
            displayPreOrder(headNode);
        }
        void showNodesPostOrder()
        {
            displayPostOrder(headNode);
        }
};

tree::tree()
{
    headNode = NULL;
}
tree::~tree()
{
    destroySubTree(headNode);
}
void tree::insertNode(int val)
{
    node* newNode = new node;
    newNode->data = val;
    newNode->leftNode = NULL;
    newNode->rightNode = NULL;

    if(headNode == NULL)
    {
        headNode = newNode;
        return;
    }

    node* tempNode = headNode;

    while(tempNode != NULL)
    {
        if(newNode->data < tempNode->data)
        {
            if(tempNode->leftNode)
                tempNode = tempNode->leftNode;
            else
            {
                tempNode->leftNode = newNode;
                break;
            }
            
        }
        else if( newNode->data > tempNode->data)
        {
            if(tempNode->leftNode)
                tempNode = tempNode->rightNode;
            else
            {
                tempNode->rightNode = newNode;
                break;
            }
        }
        else
        {
            cout << "\nRepition of elemnts detected...\n";
            break;
        }
    }
}

void tree::displayInOrder(node* tempNode)
{
    if(tempNode != NULL)
    {
        displayInOrder(tempNode->leftNode);
        cout << tempNode->data << endl;
        displayInOrder(tempNode->rightNode);
    }
}

void tree::displayPreOrder(node* tempNode)
{
    if(tempNode != NULL)
    {
        cout << tempNode->data << endl;
        displayPreOrder(tempNode->leftNode);
        displayPreOrder(tempNode->rightNode);
    }
}


void tree::displayPostOrder(node* tempNode)
{
    if(tempNode != NULL)
    {
        displayPostOrder(tempNode->leftNode);
        displayPostOrder(tempNode->rightNode);\
        cout << tempNode->data << endl;
    }
}

bool tree::searchNode(int val)
{
    node* tempNode = headNode;
    while(tempNode)
    {
        if(tempNode->data == val)
        {
            return true;
        }
        else if(val < tempNode->data)
            tempNode= tempNode->leftNode;
        else    
            tempNode = tempNode->rightNode;
    }
    return false;
}

void tree::deleteNode(int key, node* &tempNode)
{
    if(key < tempNode->data)
        deleteNode(key, tempNode->leftNode);
    else if( key > tempNode->data)
        deleteNode(key, tempNode->rightNode);
    else
        makeDeletion(tempNode);

}

void tree::makeDeletion(node* &tempNode)
{
    //make a new node pointer
    node* tempNode1;

    //if argument is null then we cannot delete any node
    if(tempNode == NULL)
        cout << "Cannot delete empty node.\n";
    //but if the new pointers rightNode is null then make the new pointer equal to the argument and then make the left side of the argument move one to the left and then delete teh node pointer
    else if(tempNode1->rightNode == NULL)
    {
        tempNode1 = tempNode;
        tempNode = tempNode->leftNode;
        delete tempNode1;
    }
    //but if the left side of the pointer is null then repeat the same thing but move one to the right and then delete the pointer as it contains the node
    else if(tempNode1->leftNode == NULL)
    {
        tempNode1 = tempNode;
        tempNode = tempNode->rightNode;
        delete tempNode1;
    }
    //but if niether of the nodes are NULL then equal the new pointer to the right of the arg node tehn treverse the left side of the new pointer until it is NULL
    //then we make the newpointer left equal to the left of arg node and tehn we equal em both and then we move arg node one to the right and then we delete the 
    //new pointer which now holdes the previous of tempNode
    else
    {
        tempNode1 = tempNode->rightNode;
        while(tempNode1->leftNode)
            tempNode1 = tempNode1->leftNode;
        
        tempNode1->leftNode = tempNode->leftNode;
        tempNode1 = tempNode;
        tempNode = tempNode->rightNode;
        delete tempNode1;
    }
}

int main()
{


    return 0;
}