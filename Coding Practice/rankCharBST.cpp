#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int data): data(data), left(nullptr), right(nullptr) {}
};

int size(Node* root)
{
    if(root == nullptr)
        return 0;
    cout << "size == " << root->data << endl;
    return 1 + size(root->left) + size(root->right);
}

int rankChar(Node* root, int tar)
{
    if(root == nullptr)
        return 0;
    cout << root->data << endl;
    if(tar < root->data)
        return rankChar(root->left, tar);
    else if(tar > root->data)
        return 1 + size(root->left) + rankChar(root->right, tar);
    return size(root->left);
}

bool flag = false;

int rankChar2(Node* root, int tar)
{
    static int rank = 0;
    if(root == nullptr)
        return 0;
    if(root->data == tar)
        return rank;
    cout << root->data << endl;
    if(root->data < tar)
    {
        rankChar2(root->left, tar);
        rank++;
        rankChar2(root->right, tar);
    }
    return rankChar2(root->left, tar);;
}
 
int main()
{
    // construct the first tree
    Node* X = nullptr;
    X = new Node(6);
    X->left = new Node(3);
    X->right = new Node(9);
    X->left->left = new Node(2);
    X->left->right = new Node(5);
    X->right->left = new Node(8);
    X->right->right = new Node(10);
    X->right->left->left = new Node(7);
    X->right->right->right = new Node(11);

    // int res = rankChar(X, 7);
    // cout << "result = " << res << endl;
    int res2 = rankChar2(X, 5);
    cout << "result2 = " << res2 << endl;
    // construct the second tree
    Node* Y = nullptr;
    Y = new Node(6);
    Y->left = new Node(8);
    Y->right = new Node(3);
    Y->left->left = new Node(2);
    Y->left->right = new Node(4);
    Y->right->left = new Node(7);
    Y->right->right = new Node(1);
    Y->left->left->left = new Node(3);
    Y->left->right->left = new Node(1);
    Y->left->right->right = new Node(7);

    return 0;
}