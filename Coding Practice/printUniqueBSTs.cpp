#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left, *right;
    node(int data): data(data), left(nullptr), right(nullptr) {}
};

vector<node*> buildBST(int st, int end)
{
    vector<node*> list;
    if(st > end)
    {
        list.push_back(nullptr);
        return list;
    }
    for(int curr = st; curr <= end; ++curr)
    {
        vector<node*> leftSubTree = buildBST(st, curr-1);
        vector<node*> rightSubTree = buildBST(curr+1, end);

        for(auto left: leftSubTree)
        {
            for(auto right: rightSubTree)
            {
                node* root = new node(curr);
                root->left = left;
                root->right = right;
                list.push_back(root);
            }
        }
    }
    return list;
}

vector<node*> generateTrees(int n)
{
    vector<node* > res = buildBST(1, n);
    return res;
}

int main()
{
    Solution solve;
    solve.generateTrees(3);
    return 0;
}