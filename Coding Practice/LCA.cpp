#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node *left, *right;
        Node(int data): data(data)
        {
            left = right = nullptr;
        }
};

bool findPath(Node *root, vector<int> &path, int k)
{
    if (root == nullptr)
        return false;
    path.push_back(root->data);
    if (root->data == k)
        return true;
    if ( (root->left and findPath(root->left, path, k)) or
        (root->right and findPath(root->right, path, k)) )
        return true;
    /**
     * If not present in subtree rooted with root, remove
     * root from path[] and return false
     */
    path.pop_back();
    return false;
}

int findLCA(Node *root, int n1, int n2)
{
    vector<int> path1, path2;
    // If either n1 or n2 is not present, return -1
    if (!findPath(root, path1, n1) or
        !findPath(root, path2, n2))
        return -1;
    int i;
    for (i = 0; i < path1.size() and i < path2.size(); i++)
        if (path1[i] != path2[i])
            break;
    return path1[i-1];
}

Node *findLCA2(Node *root, int n1, int n2)
{
    if(root == nullptr)
        return nullptr;
    if(root->data == n1 or root->data == n2)
        return root;
    Node *left_lca = findLCA2(root->left, n1, n2);
    Node *right_lca = findLCA2(root->right, n1, n2);
    if(left_lca and right_lca)
        return root;
    return left_lca ? left_lca : right_lca;
}

/**
 * This function returns pointer to LCA of two given values n1 and n2.
 * v1 is set as true by this function if n1 is found
 * v2 is set as true by this function if n2 is found
 */
Node *findLCAUtil(Node* root, int n1, int n2, bool &v1, bool &v2)
{
    if (root ==  nullptr)
        return nullptr;
    if (root->data == n1)
    {
        v1 = true;
        return root;
    }
    if (root->data == n2)
    {
        v2 = true;
        return root;
    }
    Node *left_lca  = findLCAUtil(root->left, n1, n2, v1, v2);
    Node *right_lca = findLCAUtil(root->right, n1, n2, v1, v2);
    if (left_lca and right_lca)
        return root;
    return left_lca ? left_lca : right_lca;
}

bool find(Node *root, int k)
{
    if (root == nullptr)
        return false;
    if (root->data == k or find(root->left, k) or  find(root->right, k))
        return true;
    return false;
}

Node *findLCA3(Node *root, int n1, int n2)
{
    bool v1 = false, v2 = false;
    Node *lca = findLCAUtil(root, n1, n2, v1, v2);
    if((v1 and v2) or (v1 and find(lca, n2)) or (v2 and find(lca, n1)))
        return lca;
    return nullptr;
}

void printRes(Node *root, int n1, int n2)
{
    int res = findLCA(root, n1, n2);
    int res2 = findLCA2(root, n1, n2)->data;
    int res3 = findLCA3(root, n1, n2)->data;
    printf("LCA(%d, %d) = %d\n", n1, n2, res3);
}

int main()
{
    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    printRes(root, 4, 5);
    printRes(root, 4, 6);
    printRes(root, 3, 4);
    printRes(root, 2, 4);
    return 0;
}