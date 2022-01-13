 #include<bits/stdc++.h>
using namespace std;

int dx[] = {0, 1};
int dy[] = {1, 0};

bool bIsSafe(int r, int c, int n, vector<vector<char>> input)
{
    return r < n and c < n and input[r][c] == 'O';
}

bool extractPath(int r, int c, int n, vector<vector<char>> input, vector<int>& res)
{
    if(r == n-1 and c == n-1)
    {
        res.push_back(r*n + c+1);
        return true;
    }
    if(bIsSafe(r, c, n, input))
    {
        res.push_back(r*n + c+1);
        for(int i = 0; i < 2; ++i)
        {
            int nextX = r+dx[i];
            int nextY = c+dy[i];
            if(extractPath(nextX, nextY, n, input, res))
                return true;
        }
        res.pop_back();
    }
    return false;
}

vector<int> findPath(int n, vector<vector<char>> c)
{
    vector<int> res;
    extractPath(0, 0, n, c, res);
    return res;
}

int main()
{
    int N = 4;
    vector<vector<char>> maze ={{'O', 'O', 'X', 'O'},
                    {'O', 'X', 'X', 'O'},
                    {'O', 'O', 'O', 'X'},
                    {'X', 'X', 'O', 'O'}};
    vector<int> res = findPath(N, maze);
    for(auto i: res)
        cout << i << "\t";
    return 0;
}