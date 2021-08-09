#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
        int data;
        node *left, *right;
        node(int data): data(data), left(nullptr), right(nullptr) {}
};

void traverseTree(node* root, int dist, map<int,vector<int>>& nodesWithdist)
{
    if(root == nullptr)
        return;
    nodesWithdist[dist].push_back(root->data);
    traverseTree(root->left, dist-1, nodesWithdist);
    traverseTree(root->right, dist+1, nodesWithdist);
}

void verticalOrderPrint(node* root)
{		
    map<int, vector<int> > nodesWithdist;
    traverseTree(root, 0, nodesWithdist);

    // Keys are sorted (-2,-1,0,1,2,3.....) in map
    for(auto p: nodesWithdist)
    {
        int dist = p.first;
        vector<int> vline = p.second;
        for(auto data : vline)
            cout << data << " ";
        cout <<endl;
    }	
    return;
}

void traverse2(node* root, int depth, map<int, int>& level)
{
    if(!root)
        return;
    // insert only when there is no key present
    level.insert({depth, root->data});
    traverse2(root->left, depth+1, level);
    traverse2(root->right, depth+1, level);
}

void leftView(node * root)
{
    map<int, int> level;
    traverse2(root, 0, level);
    for(auto i: level)
        cout << i.second << " ";
}

int main()
{	
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->right->left->right = new node(8);
    root->right->right->right = new node(9);

    verticalOrderPrint(root);
    leftView(root);
    return 0;
}