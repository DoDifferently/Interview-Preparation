#include<bits/stdc++.h>
using namespace std;

class node
{
    public:  
        int data;
        node * next;
        node(int data): data(data) {}
};

// break the loop and return head
node * breakChain(node * head)
{
    unordered_set<node *> hashNodes;
    node *tmp = head, *prev = nullptr;
    while(tmp)
    {
        if(hashNodes.find(tmp) != hashNodes.end())
        {
            prev->next = nullptr;
            return head;
        }
        hashNodes.insert(tmp);
        prev = tmp;
        tmp = tmp->next;
    }
    return head;
 }


