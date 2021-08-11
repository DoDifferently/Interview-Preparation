#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
        int data;
        node *left, *right;
        node(int key)
        {
            this->data = data;
            left = right = nullptr;
        }
};

int findDepth(node* root, int n)
{
    if(root == nullptr)
        return 0;
    if(root->data == n)
        return 1;
    if(root->data > n)
        return 1 + findDepth(root->left, n);
    return 1 + findDepth(root->right, n);
}

int findLCA(node* root, int a, int b)
{
    while(root)
    {
        if(root->data > a and root->data > b)
            root = root->left;
        else if(root->data < a and root->data < b)
            root = root->right;
        else
            break;
    }
    return root->data;
}

int shortestDist(node * root,int a,int b)
{
    int depth1 = findDepth(root, a);
    int depth2 = findDepth(root, b);
    int lca = findLCA(root, a, b);
    int lca_depth = findDepth(root, lca);
    return depth1 + depth2 - 2*lca_depth;
}