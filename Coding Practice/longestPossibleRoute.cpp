#include<bits/stdc++.h>
using namespace std;

bool bIsSafe(int x, int y, vector<vector<int>>& mat, vector<vector<bool>>& visited)
{
    return (x >= 0 && x < mat.size() && y >= 0 && y < mat[0].size()) &&
            mat[x][y] == 1 && !visited[x][y];
}

void findPath(int srcX, int srcY, int destX, int destY, vector<vector<int>>& mat, vector<vector<bool>>& visited, int& maxDist, int currDist)
{
    if(!mat[srcX][srcY])
        return;
    if(srcX == destX and srcY == destY)
    {
        maxDist = max(maxDist, currDist);
        return;
    }
    visited[srcX][srcY] = true;
    if(bIsSafe(srcX-1, srcY, mat, visited))
        findPath(srcX-1, srcY, destX, destY, mat, visited, maxDist, currDist+1);
    if(bIsSafe(srcX+1, srcY, mat, visited))
        findPath(srcX+1, srcY, destX, destY, mat, visited, maxDist, currDist+1);
    if(bIsSafe(srcX, srcY-1, mat, visited))
        findPath(srcX, srcY-1, destX, destY, mat, visited, maxDist, currDist+1);
    if(bIsSafe(srcX, srcY+1, mat, visited))
        findPath(srcX, srcY+1, destX, destY, mat, visited, maxDist, currDist+1);
    visited[srcX][srcY] = false;
}

int findLongestPath(int m, int n, vector<vector<int>> v)
{
    // Given there is no hurdle at source and destination cell
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int res = 0;
    findPath(0, 0, m-1, n-1, v, visited, res, 0);
    return res;
}
 
int main()
{
    vector<vector<int>> mat =
    {
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
        { 0, 0, 0, 0, 1, 0, 0, 1, 0, 0 },
        { 1, 0, 0, 0, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
        { 1, 0, 0, 0, 1, 0, 0, 1, 0, 1 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 1, 0, 0, 1, 0, 0, 0, 0, 1 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 0, 1 }
    };
    cout << "The Maximum length path is " << findLongestPath(mat.size(), mat[0].size(), mat);
    return 0;
}