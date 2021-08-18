#include<bits/stdc++.h>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

bool isInBounds(int x, int y, int M, int N)
{
    return x >= 0 and x < M and y >= 0 and y < N;
}

int dfs(int x, int y, vector<vector<int> >& matrix, vector<vector<int> >& memo)
{
    int ans = 1;
    for(int dir = 0; dir < 4; dir++)
    {
        int newX = x + dx[dir];
        int newY = y + dy[dir];
        if(isInBounds(newX, newY, matrix.size(), matrix[0].size()) and matrix[newX][newY] > matrix[x][y])
        {
            if(memo[newX][newY] != -1)
                ans = max(ans, 1 + memo[newX][newY]);
            else
                ans = 1+dfs(newX, newY, matrix, memo);
        }
    }
    return memo[x][y] = ans;
}

void printMemo(vector<vector<int> >& memo)
{
    for(int i = 0; i < memo.size(); ++i)
    {
        for(int j = 0; j < memo[i].size(); ++j)
            cout << memo[i][j] << "\t";
        cout << endl;
    }
}

int longestPathSequence(vector<vector<int> > matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int> > memo(rows, vector<int>(cols, -1));
    int maxLength = 0;
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            if(memo[i][j] == -1)
            {
                int currLength = dfs(i, j, matrix, memo);
                maxLength = max(maxLength, currLength);
            }
        }
    }
    //printMemo(memo);
    return maxLength;
}

int main(void)
{
    vector<vector<int> > matrix {{4},{5},{6},{7},{8},{7},{6},{5},{4},{3},{2},{1},{0},{5},{4},{3},{2},{1},{0}};// {{3,4,5}, {3,2,6}, {2,2,1}};//{{9,9,4}, {6,6,8}, {2,1,1}};
    cout << longestPathSequence(matrix) << endl;
    return 0;
}