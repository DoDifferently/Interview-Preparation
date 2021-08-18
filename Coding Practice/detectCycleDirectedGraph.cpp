#include<iostream>
#include<list>
#include<queue>
using namespace std;

class Graph
{
    int vertices;
    list<int> *edges;
    vector<bool> visited;
    vector<bool> in_path;
    public:
        Graph(int v)
        {
            vertices = v;
            edges = new list<int>[v];
            visited.assign(v+1, false);
            in_path.assign(v+1, false);
        }
        void AddEdge(int u, int v, bool undirected)
        {
            edges[u].push_back(v);
            if(undirected)
                edges[v].push_back(u);
        }
        bool bIsCyclic(int src)
        {
            visited[src] = true;
            in_path[src] = true;
            for(auto nbr: edges[src])
            {
                if(!visited[nbr])
                {
                    if(bIsCyclic(nbr))
                        return true;
                }
                else if(in_path[nbr])
                    return true;
            }
            in_path[src] = false;
            return false;
        }
        bool bIsCyclicGraph()
        {
            for(int i = 0; i < vertices; ++i)
            {
                if(!visited[i])
                    if(bIsCyclic(i))
                        return true;
            }
            return false;
        }
};

bool contains_cycle(int n, vector<pair<int,int> > edges)
{
    Graph gr(n);
    for(auto edge: edges)
        gr.AddEdge(edge.first, edge.second, false);
    return gr.bIsCyclicGraph();
}

int main()
{
    Graph g1_directed (7);
    g1_directed.AddEdge(0, 1, false);
    g1_directed.AddEdge(0, 2, false);
    g1_directed.AddEdge(1, 4, false);
    g1_directed.AddEdge(2, 3, false);
    g1_directed.AddEdge(3, 1, false);
    g1_directed.AddEdge(3, 5, false);
    g1_directed.AddEdge(4, 6, false);
    g1_directed.AddEdge(5, 4, false);
    g1_directed.AddEdge(6, 5, false);

    bool res = g1_directed.bIsCyclicGraph();

    if (res) {
       cout << "Cycle found in the directed graph g1" << endl;
    } else {
       cout << "Cycle not found in the directed graph g1" << endl;
    }

    Graph g2_directed (5);
    g2_directed.AddEdge(0, 1, false);
    g2_directed.AddEdge(0, 2, false);
    g2_directed.AddEdge(2, 3, false);
    g2_directed.AddEdge(3, 4, false);
    g2_directed.AddEdge(4, 1, false);

    res = g2_directed.bIsCyclicGraph();

    if (res) {
       cout << "Cycle found in the directed graph g1" << endl;
    } else {
       cout << "Cycle not found in the directed graph g1" << endl;
    }
    return 0;
}