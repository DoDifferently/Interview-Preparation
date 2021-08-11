#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *left, *right;
        Node(int data): data(data), left(nullptr), right(nullptr) {}
};

Node* insert(Node *root, int data)
{
    if(root == nullptr)
        return new Node(data);
    if(data < root->data)
        root->left = insert(root->left,data);
    else
        root->right = insert(root->right,data);
    return root;
}

void printInOrder(Node *root)
{
    if(root == nullptr)
        return;
    printInOrder(root->left);
    cout << root->data << " ,";
    printInOrder(root->right);
}

//---------BST to Sorted Linked List
class LinkedList
{
    public:
        Node * head;
        Node * tail;
};

LinkedList tree2LL(Node * root)
{
    LinkedList l;
    if(root == nullptr)
    {
        l.head = l.tail = nullptr;
        return l;
    }
    if(root->left == nullptr and root->right == nullptr)
        l.head = l.tail = root;
    else if(root->right == nullptr)
    {
        LinkedList leftLL = tree2LL(root->left);
        leftLL.tail->right = root;

        l.head = leftLL.head;
        l.tail = root;
    }
    else if(root->left == nullptr)
    {
        LinkedList rightLL = tree2LL(root->right);
        root->right = rightLL.head;

        l.head = root;
        l.tail = rightLL.tail;
    }
    else
    {
        LinkedList leftLL = tree2LL(root->left);
        LinkedList rightLL = tree2LL(root->right);
        leftLL.tail->right = root;
        root->right = rightLL.head;

        l.head = leftLL.head;
        l.tail = rightLL.tail;
    }
    return l;
}

int main()
{
    Node * root = nullptr;
    int arr[] = {8,3,10,1,6,14,4,7,13};
    for(int x : arr)
        root = insert(root,x);
    //printInOrder(root);
    LinkedList l = tree2LL(root);
    Node * temp = l.head;
    while(temp)
    {
        cout << temp->data << "--> ";
        temp = temp->right;
    }
    return 0;
}