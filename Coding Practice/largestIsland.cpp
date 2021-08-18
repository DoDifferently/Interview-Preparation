#include<bits/stdc++.h>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

bool isInBounds(int x, int y, int M, int N)
{
    return x >= 0 and x < M and y >= 0 and y < N;
}

void dfs(int x, int y, vector<vector<int> >& grid, vector<vector<int> >& visited, int& area)
{
    visited[x][y] = true;
    area++;
    // int area = 1;
    for(int dir = 0; dir < 4; dir++)
    {
        int newX = x + dx[dir];
        int newY = y + dy[dir];
        if(isInBounds(newX, newY, grid.size(), grid[0].size()) and !visited[newX][newY] and grid[newX][newY])
        {
            dfs(newX, newY, grid, visited, area);
            // int subcomponent = dfs(newX, newY, grid, visited);
            // area += subcomponent;
        }
    }
    return;
    // return area;
}

int largest_island(vector<vector<int> > grid)
{
    int max_area = 0;
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<int> > visited(rows, vector<int>(cols, false));
    for(int x = 0; x < rows; ++x)
    {
        for(int y = 0; y < cols; ++y)
        {
            if(!visited[x][y] and grid[x][y])
            {
                int curr_area = 0;
                dfs(x, y, grid, visited, curr_area);
                max_area = max(max_area, curr_area);
            }
        }
    }
    return max_area;
}

int main(void)
{
    vector<vector<int> > grid{{0,0,1,0,0,0,0,1,0,0,0,0,0},
			{0,0,0,0,0,0,0,1,1,1,0,0,0},
			{0,1,1,0,1,0,0,0,0,0,0,0,0},
			{0,1,0,0,1,1,0,0,1,0,1,0,0},
			{0,1,0,0,1,1,0,0,1,1,1,0,0},
			{0,0,0,0,0,0,0,0,0,0,1,0,0},
			{0,0,0,0,0,0,0,1,1,1,0,0,0},
            {0,0,0,0,0,0,0,1,1,0,0,0,0}};
    cout << largest_island(grid) << endl;
    return 0;
}