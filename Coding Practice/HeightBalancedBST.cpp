#include <bits/stdc++.h>
using namespace std;

class node
{
    public:
        int data;
        node *left, *right;
        node(int data): data(data), left(nullptr), right(nullptr) {}
};

node* sortedArrayToBST(int arr[], int left, int right)
{
    if(left > right)
        return nullptr;
    int mid = (left+right)/2;
    node* root = new node(arr[mid]);
    root->left = sortedArrayToBST(arr, left, mid-1);
    root->right = sortedArrayToBST(arr, mid+1, right);
    return root;
}

void preOrder(node* root)
{
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
    int arr[] = {1, 5, 11, 15, 20, 27, 38};
    int n = sizeof(arr)/sizeof(arr[0]);
    node *root = sortedArrayToBST(arr, 0, n-1);
    cout << "PreOrder Traversal of constructed BST \n";
    preOrder(root);
    return 0;
}