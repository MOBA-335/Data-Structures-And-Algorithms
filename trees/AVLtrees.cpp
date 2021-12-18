#include<iostream>
using namespace std;

struct node
{
    int data;
    int height;
    node* left;
    node* right;
};

int Max(int h1, int h2)
{
    if(h1>h2)
        return h1;
    else
        return h2;
}

int Height(node* tempNode)
{
    if(!tempNode)
        return -1;
    else 
        return tempNode->height;
}

node* singleRotateLeft(node* t1)
{
    node* t2;

    t2 = t1->left;
    t1->left = t2->right;
    t2->right = t1;

    t1->height = Max(Height(t1->left), Height(t1->right)) + 1;
    t2->height = Max(Height(t2->left), Height(t2->right)) + 1;

    return t2;
}

node* singleRotateRight(node* t1)
{
    node* t2;

    t2 = t1->right;
    t1->right = t2->left;
    t2->left = t1;
    
    t1->height = Max(Height(t1->left), Height(t1->right)) + 1;
    t2->height = Max(Height(t2->left), Height(t2->right)) + 1;
    
    return t2;
}
node* doubleRotateLeft(node* tempNode)
{
    tempNode->left = singleRotateRight(tempNode->left);

    return singleRotateLeft(tempNode);
}
node* doubleRotateRight(node* tempNode)
{
    tempNode->right = singleRotateLeft(tempNode->right);

    return singleRotateRight(tempNode);
}


node* insert(node* root, node* parent, int val)
{
    if(root == NULL)
    {
        root = new node;
        root->data = val;
        root->height = 0;
        root->left = NULL;
        root->right = NULL;
    }
    else if(val < root->data)
    {
        root->left = insert(root->left, root, val);
        if(Height((root->left) - Height(root->right)) == 2)
        {
            if(val <root->left->data)
                root = singleRotateLeft(root);
            else
                root = doubleRotateRight(root);
        }
    }
    else if(val > root->data)
    {
        root->right = insert(root->right, root, val);
        if((Height(root->left) - Height(root->right)) == 2)
        {
            if(val > root->right->data)
                root = singleRotateRight(root);
            else
                root = doubleRotateRight(root);
        }
    }

    root->height = Max(Height(root->left), Height(root->right)) + 1;
    return root;
}

void printInOrder(node* temp)
{
    if(temp)
    {
        
        printInOrder(temp->left);
        printInOrder(temp->right);
        cout << temp->data << endl;
    }
}
int main()
{  
    node* start = NULL;
    start = insert(start, NULL, 10);
    start = insert(start, NULL, 20);
    start = insert(start, NULL, 30);
    start = insert(start, NULL, 40);
    start = insert(start, NULL, 55);
    start = insert(start, NULL, 25);

    printInOrder(start);

    return 0;
}