#include<bits/stdc++.h>
using namespace std;
/*** Using DFS ***
class Graph
{
    int vertices;
    list<int> *edges;
    public:
        Graph(int v)
        {
            vertices = v;
            edges = new list<int>[v];
        }
        void addEdge(int u, int v, bool undirected)
        {
            edges[u].push_back(v);
            if(undirected)
                edges[v].push_back(u);
        }
        void dfs(int src, vector<bool>& visited, int& cnt)
        {
            visited[src] = true;
            cnt++;
            for(auto nbr: edges[src])
                if(!visited[nbr])
                    dfs(nbr, visited, cnt);
        }
};

int count_pairs(int N, vector<pair<int,int> > astronauts)
{
    Graph gr(N);
    for(auto curr: astronauts)
        gr.addEdge(curr.first, curr.second, true);
    int res = 0, sum = 0;
    vector<bool> visited(N, false);
    for(int i = 0; i < N; ++i)
    {
        if(!visited[i])
        {
            int curr = 0;
            gr.dfs(i, visited, curr);
            res += (sum*curr);
            sum += curr;
        }
    }
    return res;
}
*/

int count_pairs(int N, vector<pair<int,int> > astronauts)
{
    map<int, int> assignCountry;
    vector<int> countAstronauts(N+1, 0);
    int country = 1;
    for(auto curr: astronauts)
    {
        if(assignCountry.count(curr.first))
        {
            assignCountry[curr.second] = assignCountry[curr.first];
            countAstronauts[assignCountry[curr.first]]++;
        }
        else if(assignCountry.count(curr.second))
        {
            assignCountry[curr.first] = assignCountry[curr.second];
            countAstronauts[assignCountry[curr.first]]++;
        }
        else
        {
            assignCountry[curr.first] = assignCountry[curr.second] = country;
            countAstronauts[country] = 2;
            country++;
        }
    }
    for(int i = 0; i < N; ++i)
    {
        if(assignCountry.count(i) == 0)
        {
            countAstronauts[country] = 1;
            country++;
        }
    }
    int res = 0, sum = 0;
    // for(int i = 0; i < country-1; ++i)
    // {
    //     for(int j = i+1; j < country; ++j)
    //         res += (countAstronauts[i] * countAstronauts[j]);
    // }
    for(int i = 0; i < country; ++i)
    {
        res += (sum*countAstronauts[i]);
        sum += countAstronauts[i];
    }
    return res;
}

int main(void)
{
    int N = 4;
    vector<pair<int,int> > astronauts {{0, 2}};
    cout << count_pairs(N, astronauts) << endl;
    return 0;
}