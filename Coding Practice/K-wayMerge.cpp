#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data, arrayNum, idx;
};

class NodeCompare
{
    public:
        bool operator()(const node& a, const node& b)
        {
            return a.data > b.data;
        }
};

vector<int> mergeKArrays(vector<vector<int> > arrays)
{
    int k = arrays.size();
    vector<int> finalSortedArray;
    priority_queue<node, vector<node>, NodeCompare> MinHeap;
    for(int i = 0; i < k; ++i)
    {
        if(arrays[i].size() > 0)
        {
            MinHeap.push({arrays[i][0], i, 0});
        }
    }
    while(!MinHeap.empty())
    {
        node curr = MinHeap.top();
        MinHeap.pop();
        finalSortedArray.push_back(curr.data);
        int idx = curr.idx + 1;
        if(idx < arrays[curr.arrayNum].size())
            MinHeap.push({arrays[curr.arrayNum][idx], curr.arrayNum, idx});
    }
    return finalSortedArray;
}

int main(void)
{
    vector<vector<int>> arrays {{1, 3, 15}, {2, 4, 6}, {0, 9, 10, 11}};
    vector<int> res = mergeKArrays(arrays);
    for(auto i: res)
        cout << i << "\t";
    return 0;
}