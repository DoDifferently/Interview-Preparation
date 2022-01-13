#include <bits/stdc++.h>
using namespace std;

//Node to store the data (Linked List)
struct Node
{
    string key;
    int value;
    Node(string key,int value)
    {
        this->key = key;
        this->value = value;
    }
};


// simple single threaded LRUCache
class LRUCache
{
    unordered_map<string, list<Node>::iterator > hash;
    // each entry in linked list is <key, value>
    list<Node> cache;
    int capacity; // total capacity
    
    public:
        LRUCache(int capacity): capacity(capacity) {}
        
        int* getValue(string key)
        {
            if(hash.count(key) == 0)
                return nullptr;
            auto it = hash[key];
            int value = it->value;

            // insert in the front
            cache.push_front(*it); // Node(key, value)
            cache.erase(it);
            hash[key] = cache.begin();
            return &cache.begin()->value;
        }
        
        void insertKeyValue(string key, int value)  // insert (key, value)
        {
            if(hash.count(key))    // update the value
            {
                auto it = hash[key];
                it->value = value;
            }
            else
            {
                //check if cache is full or not -> remove the least recently used item from cache
                if(cache.size() == capacity)
                {
                    Node last = cache.back();
                    cache.pop_back();
                    hash.erase(last.key);
                }
                else
                {
                    Node newNode(key, value);
                    cache.push_front(newNode);
                    hash[key] = cache.begin();
                }
            }
        }
        
        string mostRecentKey()
        {
            return cache.front().key;
        }

        string print()
        {
            string result = "";
            for (auto& x : hash)
                result += "(" + x.first + "," + std::to_string(x.second->value) + "),";
            return result;
        }
};


int main()
{
    LRUCache lru(3);
    lru.insertKeyValue("mango",10);
    lru.insertKeyValue("apple",20);
    lru.insertKeyValue("guava",30);
    cout << lru.mostRecentKey() <<endl;

    lru.insertKeyValue("mango",40);
    cout << lru.mostRecentKey() <<endl;

    int *orders = lru.getValue("mango");
    if(orders!=NULL)
        cout<<"Order of Mango "<<*orders <<endl;

    lru.insertKeyValue("banana",20);

    if(lru.getValue("apple")==NULL)
        cout<<"apple doesn't exist";
        
    if(lru.getValue("guava")==NULL)
        cout<<"guava doesn't exist";
        
    if(lru.getValue("banana")==NULL)
        cout<<"banana doesn't exist";
        
    if(lru.getValue("mango")==NULL)
        cout<<"mango doesn't exist";
    return 0;
}