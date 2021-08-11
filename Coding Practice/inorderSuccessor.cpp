#include <iostream>
using namespace std;

class node
{
    public:
        int data;
        node *left, *right, *parent;
        node(int data): data(data), left(nullptr), right(nullptr) {}
};

node* minValue(node *root)
{
    if(root == nullptr)
        return root;
    while(root->left)
        root = root->left;
    return root;
}

node *inOrderSuccessor(node *root, node *target)
{
    if(root == nullptr or target == nullptr)
        return nullptr;
    if(target->right)
        return minValue(target->right);
    
    node *succ = nullptr;
    while(root)
    {
        if(target->data < root->data)
        {
            succ = root;
            root = root->left;
        }
        else if(target->data > root->data)
            root = root->right;
        else
            break;
    }
    return succ;
}

node* insert(node *root, int data)
{
    if(root == nullptr)
        return new node(data);
    if(data <= root->data)
        root->left = insert(root->left,data);
    else
        root->right = insert(root->right,data);
    return root;
}

int main()
{
    node *root = nullptr;
    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 22);
    root = insert(root, 4);
    root = insert(root, 12);
    root = insert(root, 10);
    root = insert(root, 14);
    node *temp = root->left->right->right;
    cout << "\n Inorder Successor of " << temp->data;
    node *succ = inOrderSuccessor(root, temp);
    if (succ)
        cout << " is " << succ->data << endl;
    else
        cout <<" doesn't exit" << endl;
    return 0;
}