#include <bits/stdc++.h>
using namespace std;

struct trieNode
{
    trieNode* child[2];
    trieNode()
    {
        child[0] = child[1] = nullptr;
    }
    ~trieNode()
    {
        for(int i = 0; i < 2; ++i)
        {
            delete child[i];
            child[i] = nullptr;
        }
    }
};

class Trie
{
    trieNode* root;
    public:
        Trie(): root(new trieNode()) {}
        ~Trie()
        {
            delete root;
            root = nullptr;
        }
        void insert(int num)
        {
            trieNode* tmp = root;
            for(int i = 31; i >= 0; i--)
            {
                bool bit = num & (1<<i);
                if(tmp->child[bit] == nullptr)
                    tmp->child[bit] = new trieNode();
                tmp = tmp->child[bit];
            }
        }

        int getMaxXor(int num)
        {
            int curr_xor = 0;
            trieNode* tmp = root;
            for(int i = 31; i >= 0; i--)
            {
                bool bit = num & (1 << i);
                if(tmp->child[!bit])
                {
                    curr_xor |= (1 << i);
                    tmp = tmp->child[!bit];
                }
                else
                    tmp = tmp->child[bit];
            }
            return curr_xor;
        }
};

int max_xor_pair(vector<int> arr)
{
    Trie trie;
    int max_xor = 0;
    for(auto num: arr)
    {
        trie.insert(num);
        int curr_xor = trie.getMaxXor(num);
        max_xor = max(max_xor, curr_xor);
    }
    return max_xor;
}

int main()
{
    vector<int> input = {3,10,5,25,9,2};
    cout<< max_xor_pair(input)<<endl;
    return 0;
}