#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *left, *right;
        Node(int data): data(data), left(nullptr), right(nullptr) {}
};

void flatten(struct Node* root)
{
    if (root == nullptr || (root->left == nullptr && root->right == nullptr))
        return;
    // if root->left exists then we have to make it root->right
    if (root->left)
    {
        flatten(root->left);	
        // store the node root->right
        struct Node* tmpRight = root->right;
        root->right = root->left;
        root->left = NULL;
        // find the position to insert the stored value
        struct Node* tmp = root->right;
        while (tmp->right)
            tmp = tmp->right;
        // insert the stored value
        tmp->right = tmpRight;
    }
    // now call the same function for root->right
    flatten(root->right);
}

void inorder(struct Node* root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(6);

    flatten(root);
    cout << "The Inorder traversal after flattening binary tree ";
    inorder(root);
    return 0;
}