#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int numRows, numCols;
    vector<vector<int>> initialMatrix;
    public:
        void setRowsAndCols(int rows, int cols)
        {
            numRows = rows;
            numCols = cols;
        }
        void setInitialMatrix(vector<vector<int>>& mat)
        {
            initialMatrix.resize(numRows, vector<int>(numCols));
            initialMatrix.insert(initialMatrix.end(), mat.begin(), mat.end());
            for(int i = 0; i < numRows; ++i)
                for(int j = 0; j < numCols; ++j)
                    initialMatrix[i][j] = mat[i][j];
        }
        int filltheMatrix(int row, int col, vector<vector<int>>& mat)
        {
            if(row < 0 or col < 0)
                return -numRows*numCols;
            if(mat[row][col] != -1)
                return mat[row][col];
            if(initialMatrix[row][col] = 0)
                mat[row][col] = 0;
            else
                mat[row][col] = initialMatrix[row][col] + max(filltheMatrix(row, col-1, mat), filltheMatrix(row-1, col, mat));
            return mat[row][col];
        }
        vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
        {
            setRowsAndCols(mat.size()-1, mat[0].size()-1);
            setInitialMatrix(mat);
            initialMatrix.assign(numRows, vector<int>(numCols, -1));
            filltheMatrix(numRows-1, numCols-1, mat);
            return mat;
        }
};