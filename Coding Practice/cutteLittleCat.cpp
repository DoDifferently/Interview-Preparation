#include <bits/stdc++.h>
using namespace std;

struct trieNode
{
    bool isEndOfWord;
    unordered_map<char, trieNode *> childs;
    trieNode(): isEndOfWord(false) {}
};

class Trie
{
    trieNode* root;
    public:
        Trie(): root(new trieNode()) {}
        void insert(string word)
        {
            trieNode *tmp = root;
            for(char ch: word)
            {
                if(tmp->childs.find(ch) == tmp->childs.end())
                    tmp->childs[ch] = new trieNode();
                tmp = tmp->childs[ch];
            }
            tmp->isEndOfWord = true;
        }

        void modifiedSearch(int idx, string document, unordered_set<string>& hashSet)
        {
            trieNode* tmp = root;
            for(int i = idx; i < document.length(); ++i)
            {
                char ch = document[i];
                if(tmp->childs.find(ch) == tmp->childs.end())
                    return;
                tmp = tmp->childs[ch];
                if(tmp->isEndOfWord)
                    hashSet.insert(document.substr(idx, i-idx+1));
            }
        }
};

void documentSearch(string document, vector<string> words)
{
    Trie trie;
    // 1. Insert all words in the trie
    for(string word: words)
        trie.insert(word);
    // 2. Search all suffixes of document in trie
    unordered_set<string> hashSet;
    for(int idx = 0; idx < document.length(); ++idx)
        trie.modifiedSearch(idx, document, hashSet);
    // 3. Check in the hashSet for the result
    for(string word: words)
    {
        if(hashSet.find(word) != hashSet.end())
            cout << word << " - Yes" << endl;
        else
            cout << word << " - No" << endl;
    }
}

int main(void)
{
    string document  ="little cute cat loves to code in c++, java & python";
    vector<string> words{"cute cat", "ttle", "cutest", "cat", "quick", "big"};
    documentSearch(document,words);
    return 0;
}