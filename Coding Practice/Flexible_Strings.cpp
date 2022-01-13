/*
    https://www.geeksforgeeks.org/swiggy-interview-experience-for-sde-ii/
    find out all unique characters in given strings, each time select one character
    and check if we can convert other characters to this character. can use DFS to
    verify If we can convert one character to another
*/
#include <bits/stdc++.h>
using namespace std;

static const int NUM_CHARS = 26;

class Graph
{
    int vertices;
    list<int> *adjList;
    vector<bool> visited;
    public:
        Graph(int vertices)
        {
            this->vertices = vertices;
            adjList = new list<int>[vertices];
            visited.assign(vertices, false);
        }

        void addEdge(int from, int to, bool IsUndirected = false)
        {
            adjList[from].push_back(to);
            if(IsUndirected)
            {
                adjList[to].push_back(from);
            }
        }

        void resetVisitedArr()
        {
            visited.assign(vertices, false);
        }

        bool dfs(int src, int dest)
        {
            if(src == dest)
                return true;
            visited[src] = true;
            for(auto nbr: adjList[src])
            {
                if(!visited[nbr] and dfs(nbr, dest))
                    return true;
            }
            return false;
        }
};

int main(void)
{
    map<char, char> hash;
    string input;
    cin >> input;
    int numOper;
    cin >> numOper;

    Graph gr(NUM_CHARS);
    char from, to;
    while(numOper--)
    {
        cin >> from >> to;
        int u = from - 'a';
        int v = to - 'a';
        cout << u << "   " << v << endl;
        gr.addEdge(u, v);
    }

    unordered_set<char> uniqChars;
    for(auto ch: input)
    {
        uniqChars.insert(ch);
    }
    int len = input.length();
    bool flag = false;
    for(auto uniq_ch: uniqChars)
    {
        int dest = uniq_ch - 'a';
        bool res = false;
        int i = 0;
        for(; i < len; ++i)
        {
            int src = input[i] - 'a';
            if(src == dest)
                continue;
            else if(gr.dfs(src, dest))
                continue;
            else
                break;
        }
        if(i == len)
            flag = true;
    }
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}