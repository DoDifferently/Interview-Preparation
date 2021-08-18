#include<bits/stdc++.h>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

struct node
{
    int x, y, dist;
    node(int x, int y, int dist): x(x), y(y), dist(dist) {}
};

class compare
{
    public:
        bool operator()(const node& a, const node& b)
        {
            return a.dist <= b.dist;
        }
};

bool isInBounds(int x, int y, int M, int N)
{
    return x >= 0 and x < M and y >= 0 and y < N;
}

int shortest_path(vector<vector<int> > grid)
{
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<int> > dist(rows, vector<int>(cols, INT_MAX));
    priority_queue<node, vector<node>, compare> MinHeap;
    MinHeap.push({0, 0, grid[0][0]});
    dist[0][0] = grid[0][0];
    while(!MinHeap.empty())
    {
        node curr = MinHeap.top();
        MinHeap.pop();
        for(int dir = 0; dir < 4; dir++)
        {
            int newX = curr.x + dx[dir];
            int newY = curr.y + dy[dir];
            if(isInBounds(newX, newY, rows, cols) and dist[newX][newY] > curr.dist + grid[newX][newY])
            {
                dist[newX][newY] = curr.dist + grid[newX][newY];
                MinHeap.push({newX, newY, dist[newX][newY]});
            }
        }
    }
    return dist[rows-1][cols-1];
}

int main(void)
{
    vector<vector<int> > grid {{1, 2, 3}, {4, 5, 6}};
    cout << shortest_path(grid) << endl;
    return 0;
}