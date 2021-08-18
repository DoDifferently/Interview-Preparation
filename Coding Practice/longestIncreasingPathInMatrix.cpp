#include<bits/stdc++.h>
using namespace std;

class Solution
{
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    bool bIsInBounds(int x, int y, int numRows, int numCols)
    {
        return x >= 0 and x < numRows and y >= 0 and y < numCols;
    }

    int dfs(int x, int y, vector<vector<int>>& matrix, vector<vector<int>>& memo)
    {
        int ans = 0;
        for(int dir = 0; dir < 4; ++dir)
        {
            int newX = x + dx[dir];
            int newY = y + dy[dir];
            if(bIsInBounds(newX, newY, matrix.size(), matrix[0].size()) and matrix[newX][newY] > matrix[x][y])
            {
                if(memo[newX][newY] != -1)
                    ans = max(ans, 1 + memo[newX][newY]);
                else
                {
                    dfs(newX, newY, matrix, memo);
                    ans = max(ans, 1 + memo[newX][newY]);
                }
            }
        }
        return memo[x][y] = ans;
    }

    public:
        int longestIncreasingPath(vector<vector<int>>& matrix)
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
            return maxLength;
        }
};

int main(void)
{
    Solution solve;
    vector<vector<int> > matrix {{13,5,13,9},{5,0,2,9},{10,13,11,10},{0,0,13,13}};
    cout << solve.longestIncreasingPath(matrix) << endl;
    return 0;
}