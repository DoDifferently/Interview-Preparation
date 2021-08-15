#include<iostream>
#include<list>
#include<queue>
using namespace std;

class Graph
{
    int vertices;
    list<int> *edges;
    vector<int> visited;
    public:
        Graph(int v)
        {
            vertices = v;
            edges = new list<int>[v];
            visited.assign(v+1, false);
        }
        void addEdge(int u, int v, bool undirected)
        {
            edges[u].push_back(v);
            if(undirected)
                edges[v].push_back(u);
        }
        bool bfs(int src)
        {
            vector<int> parent(vertices, -1);
            queue<int> que;
            que.push(src);
            visited[src] = true;
            while(!que.empty())
            {
                int curr = que.front();
                que.pop();
                for(auto nbr: edges[curr])
                {
                    if(!visited[nbr])
                    {
                        parent[nbr] = curr;
                        que.push(nbr);
                        visited[nbr] = true;
                    }
                    else if(parent[curr] != nbr)
                        return true;
                }
            }
            return false;
        }
};

bool contains_cycle(int n, vector<pair<int,int> > edges)
{
    Graph gr(n+1);
    for(auto edge: edges)
        gr.addEdge(edge.first, edge.second, true);
    return gr.bfs(0);
}