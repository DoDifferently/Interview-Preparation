#include<iostream>
#include<list>
#include<queue>
using namespace std;

class Graph
{
    int vertices;
    list<int> *edges;
    vector<int> dist;
    public:
        Graph(int v)
        {
            vertices = v;
            edges = new list<int>[v];
            dist.assign(v+1, 0);
        }
        void addEdge(int u, int v, bool undirected)
        {
            edges[u].push_back(v);
            if(undirected)
                edges[v].push_back(u);
        }
        int getMinCost(int src, int target)
        {
            int cost = 1;
            queue<int> que;
            que.push(src);
            dist[src] = 0;
            while(!que.empty())
            {
                int curr = que.front();
                que.pop();
                for(auto nbr: edges[curr])
                {
                    if(dist[nbr] != 0)
                        continue;
                    que.push(nbr);
                    dist[nbr] = 1+dist[curr];
                    if(nbr == target)
                        return dist[target];
                }
            }
            return dist[target];
        }
};

void updateBoard(vector<int>& board, vector<pair<int,int>> snakes, vector<pair<int,int>> ladders)
{
    for(auto snake: snakes) // (head, tail)
        board[snake.first] = snake.second - snake.first;
    for(auto ladder: ladders)
        board[ladder.first] = ladder.second - ladder.first;
}

int min_dice_throws(int n,vector<pair<int,int> > snakes, vector<pair<int,int> > ladders)
{
    vector<int> board(n+1, 0);
    updateBoard(board, snakes, ladders);
    Graph gr(n+1);
    for(int u = 1; u < n; u++)
    {
        for(int dice = 1; dice <= 6; dice++)
        {
            int v = u + dice;
            v += board[v];
            if(v <= n)
                gr.addEdge(u, v, false);
        }
    }
    return gr.getMinCost(1, n);
}