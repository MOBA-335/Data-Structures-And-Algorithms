#include<iostream>
using namespace std;

class bst
{
    private:
        struct node
        {
            int data;
            node* right;
            node* left;
        };
        node* root;
        void printInOrder(node* tempNode);
        void printInPreOrder(node* tempNode);
        void printInPostOrder(node* tempNode);
        void deleteNode(node* tempNode, int key);
        void makeDeletion(node* tempNode);
    public:
        bst();
        ~bst();
        void insert(int val);
        void remove(int key);
        void search(int key);
        void displayInOrder();
        void displayInPostOrder();
        void displayInPreOrder();
};

bst::bst()
{
    root = NULL;
}

void bst::insert(int val)
{
    node* newNode = new node;
    
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;

    node* tempNode = root;

    if(root == NULL)
    {
        root = newNode;
    }
    else
    {
        while(tempNode != NULL)
        {
            if(val < tempNode->data)
            {
                if(tempNode->left)
                {
                    tempNode = tempNode->left;
                }
                else
                {
                    tempNode->left = newNode;
                    break;
                }
            }
            else if(val > tempNode->data)
            {
                if(tempNode->right)
                {
                    tempNode = tempNode->right;
                }
                else
                {
                    tempNode->right = newNode;
                    break;
                }
            }
            else
            {
                cout << "\nDuplication Detected...\nCannot Insert this value.\n";
                break;
            }
        }
    }
}

void bst::remove(int key)
{
    deleteNode(root, key);   
}

void bst::deleteNode(node* tempNode, int key)
{
    if(key < tempNode->data)
        deleteNode(tempNode->left, key);
    else if(key > tempNode->data)
        deleteNode(tempNode->right, key);
    else
        makeDeletion(tempNode); 
}

void bst::makeDeletion(node* tempPtr)
{
    node* tempNodePtr;

    if(tempPtr == NULL)
        cout << "\nCannot delete Empyt Node.\n";
    else if(tempPtr->left == NULL)
    {
        tempNodePtr = tempPtr;
        tempPtr = tempPtr->right;
        delete tempNodePtr; 
    } 
    else if(tempPtr->right == NULL)
    {
        tempNodePtr = tempPtr;
        tempPtr = tempPtr->left;
        delete tempNodePtr;
    }
    else
    {
        tempNodePtr = tempPtr->right;

        while(tempNodePtr->left != NULL)
            tempNodePtr = tempNodePtr->left;
        
        tempNodePtr->left = tempPtr->left;
        tempNodePtr = tempPtr;
        tempPtr = tempPtr->right;
        delete tempNodePtr;
    }
}

void bst::printInOrder(node* tempNode)
{
    if(tempNode)
    {
        printInOrder(tempNode->left);
        cout << tempNode->data << endl;
        printInOrder(tempNode->right);
    }
}

void bst::printInPostOrder(node* tempNode)
{
    if(tempNode)
    {
        printInPostOrder(tempNode->left);
        printInPostOrder(tempNode->right);
        cout << tempNode->data << endl;
    }
}

void bst::printInPreOrder(node* tempNode)
{
    if(tempNode)
    {
        cout << tempNode->data << endl;
        printInPreOrder(tempNode->left);
        printInPreOrder(tempNode->right);
    }
}

void bst::displayInOrder()
{
    printInOrder(root);
}

void bst::displayInPostOrder()
{
    printInPostOrder(root);
}

void bst::displayInPreOrder()
{
    printInPreOrder(root);
}

void bst::search(int key)
{
    node* tempNode = root;

    if(root == NULL)
        cout << "\nThe Tree is Empty.\n";
    else
    {
        while(tempNode != NULL)
        {
            if(key < tempNode->data)
            {
                if(tempNode->left)
                    tempNode = tempNode->left;
                else
                {
                    cout << "\nThe Required Number is not in the tree.\n";
                    break;
                }
            }
            else if(key > tempNode->data)
            {
                if(tempNode->right)
                    tempNode = tempNode->right;
                else
                {
                    cout << "\nThe Required Number is not in the tree.\n";
                    break;
                }
            }
            else
            {
                cout << "\nThe Requied Number is Present in the Tree.\n";
                break;
            }
        }
    }
}
int main()
{
    

    return 0;
}