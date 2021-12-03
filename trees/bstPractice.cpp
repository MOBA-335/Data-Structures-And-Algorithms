#include<iostream>
using namespace std;

class bst
{
    private:
        struct node
        {
            int data;
            node* left;
            node* right;
        };
        node* root;

        void printInOrder(node* );
        void printInPreOrder(node* );
        void printInPostOrder(node* );
        void makeDeletion(node* );
        void DeleteWholetree(node* );

    public:
        bst();
        ~bst();
        void insert(int val);
        void search(int val);
        void DisplayInOrder();
        void Delete(int val);
        void DisplayInPreOrder();
        void DisplayInPostOrder();
        void DeleteTree();       
};

bst::bst()
{
    root = NULL;
}

bst::~bst()
{
    DeleteWholetree(root);
}

void bst::insert(int val)
{
    node* newNode = new node;

    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;

    if(root == NULL)
    {
        root = newNode;
        return;
    }

    node* tempNode = root;

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
            cout << "\nRepetition of Elements Detected...\n";
            break;
        }
    }
}

void bst::search(int val)
{
    if(root == NULL)
    {
        cout << "\nTree is Empty...\n";
        return;
    }
    else
    {
        node* tempNode = root;

        while(tempNode != NULL)
        {
            if(tempNode->data > val)
            {
                if(tempNode->left)
                {
                    tempNode = tempNode->left;
                }
                else
                {
                    cout << "\nRequired Element is not in list...\n";
                    break;
                }
            }
            else if(tempNode->data < val)
            {
                if(tempNode->right)
                {
                    tempNode = tempNode->right;
                }
                else
                {
                    cout << "\nRequired Element is not in list...\n";
                    break;
                }
            }
            else
            {
                cout << "\nThe Elemnt is present in the Tree...\n";
                break;
            }
        }
    }
}

void bst::DisplayInOrder()
{
    printInOrder(root);
}

void bst::DisplayInPreOrder()
{
    printInPreOrder(root);
}

void bst::DisplayInPostOrder()
{
    printInPostOrder(root);
}

void bst::printInOrder(node* tempNode)
{
    if(tempNode != NULL)
    {
        printInOrder(tempNode->left);
        cout << tempNode->data << " ";
        printInOrder(tempNode->right);
    }
}

void bst::printInPreOrder(node* tempNode)
{
    if(tempNode != NULL)
    {
        cout << tempNode->data << " ";
        printInPreOrder(tempNode->left);
        printInPreOrder(tempNode->right);
    }
}

void bst::printInPostOrder(node* tempNode)
{
    if(tempNode != NULL)
    {
        printInPostOrder(tempNode->left);
        printInPostOrder(tempNode->right);
        cout << tempNode->data << " ";
    }
}

void bst::Delete(int val)
{
    if(root == NULL)
    {
        cout << "\nThe Tree is Empty...\n";
        return;
    }
    else
    {
        node* tempNode = root;

        while(tempNode != NULL)
        {
            if(tempNode->data > val)
            {
                if(tempNode->left)
                {
                    tempNode = tempNode->left;
                }
                else
                {
                    cout << "\nThe required elemnet is not in the tree...\n";
                    break;
                }
            }
            else if(tempNode->data < val)
            {
                if(tempNode->right)
                {
                    tempNode = tempNode->right;
                }
                else
                {
                    cout << "\nThe required element is not in the tree...\n";
                    break;
                }
            }
            else
            {
                makeDeletion(tempNode);
                cout << "\nDeletion has been Made...\n";
                break;
            }
        }
    }
} 

void bst::makeDeletion(node* tempNode)
{
    node* nodePtr;

    if(tempNode == NULL)
    {
        cout << "\nCannot delete empty node.\n";
        return;
    }
    else if(nodePtr->right == NULL)
    {
        nodePtr = tempNode;
        tempNode = tempNode->left;
        delete nodePtr;
    }
    else if(nodePtr->left == NULL)
    {
        nodePtr = tempNode;
        tempNode = tempNode->right;
        delete nodePtr;
    }
    else
    {
        nodePtr = tempNode->right;

        while(nodePtr->left)
            nodePtr = nodePtr->left;

        nodePtr->left = tempNode->left;
        nodePtr = tempNode;
        tempNode = tempNode->right;
        delete nodePtr;
    }
}

void bst::DeleteWholetree(node* tempNode)
{
    if(tempNode != NULL)
    {
        DeleteWholetree(tempNode->left);
        DeleteWholetree(tempNode->right);
        delete tempNode;
    }
}

void bst::DeleteTree()
{
    DeleteWholetree(root);
}

int main()
{
    bst b;

    b.insert(6);
    b.insert(7);
    b.insert(4);
    b.insert(8);
    b.insert(2);
    b.insert(11);
    b.insert(17);
    b.insert(5);
    b.insert(19);
    b.insert(1);
    b.insert(22);
    cout << "\nDisplaying In Order: ";
    b.DisplayInOrder();
    cout << "\n";

    cout << "\nDisplaying In Pre Order: ";
    b.DisplayInPreOrder();
    cout << "\n";

    cout << "\nDisplaying In Post Order: ";
    b.DisplayInPostOrder();
    cout << "\n";

    b.Delete(17);
    b.Delete(2);
    b.Delete(4);

    cout << "\nDisplaying In Order: ";
    b.DisplayInOrder();
    cout << "\n";

    cout << "\nDisplaying In Pre Order: ";
    b.DisplayInPreOrder();
    cout << "\n";

    cout << "\nDisplaying In Post Order: ";
    b.DisplayInPostOrder();
    cout << "\n";

    

    return 0;
}