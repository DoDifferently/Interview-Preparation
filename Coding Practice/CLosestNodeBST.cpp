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

void minDiff(node *root, int k, int &min_diff, int &res)
{
    if(!root)
        return;
    if(root->data == k)
    {
        res = k;
        return;
    }
    int diff = abs(k - root->data);
    if(diff < min_diff)
    {
        min_diff = diff;
        res = root->data;
    }
    if(k < root->data)
        minDiff(root->left, k, min_diff, res);
    else
        minDiff(root->right, k, min_diff, res);
}

int closestValue(node *root, int k)
{
    int min_diff = INT_MAX, ans = -1;
    minDiff(root, k, min_diff, ans);
    return ans;
}

int closestValueIter(node *root, int k)
{
    int min_diff = INT_MAX, ans = -1;
    while(root)
    {
        if(root->data == k)
            return k;
        int diff = abs(k - root->data);
        if(diff < min_diff)
        {
            min_diff = diff;
            ans = root->data;
        }
        if(k < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return ans;
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
    cout << "\n Closest Value = " << closestValue(root, 18);
    cout << "\n Closest Value iter = " << closestValueIter(root, 18);
    return 0;
}