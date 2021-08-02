#include <bits/stdc++.h>
using namespace std;

class NQueen
{
    int numQueens;
    int numWays;
    vector<string> chessBoard;
    vector<vector<string>> res;

    bool m_InSafeRow(int row, int col)
    {
        for(int r = 0; r < row; ++r)
            if(chessBoard[r][col] == 'Q')
                return false;
        return true;
    }
    
    bool m_InSafeCol(int row, int col)
    {
        for(int c = 0; c < col; ++c)
            if(chessBoard[row][c] == 'Q')
                return false;
        return true;
    }

    bool m_InSafeUpperLeftDiagonal(int row, int col)
    {
        for(int r = row, c = col; r >= 0 and c >= 0; --r, --c)
            if(chessBoard[r][c] == 'Q')
                return false;
        return true;
    }

    bool m_InSafeBottomLeftDiagonal(int row, int col)
    {
        for(int r = row, c = col; r < numQueens and c >= 0; ++r, --c)
            if(chessBoard[r][c] == 'Q')
                return false;
        return true;
    }

    bool m_IsCellSafe(int row, int col)
    {
        return m_InSafeRow(row, col) and m_InSafeCol(row, col) and
        m_InSafeUpperLeftDiagonal(row, col) and m_InSafeBottomLeftDiagonal(row, col);
    }

    void m_PrintChessBoard()
    {
        cout  << "\n ================= \n";
        for(string s: chessBoard)
            cout << s << endl;
        cout  << "\n ================= \n";
    }

    public:
        NQueen(int numQueens): numQueens(numQueens)
        {
            string str(numQueens, '.');
            chessBoard.resize(numQueens, str);
            numWays = 0;
        }

        void PlaceNQueens(int col)
        {
            if(col == numQueens)
            {
                // m_PrintChessBoard();
                res.push_back(chessBoard);
                numWays++;
                return;
            }
            for(int row = 0; row < numQueens; ++row)
            {
                if(m_IsCellSafe(row, col))
                {
                    chessBoard[row][col] = 'Q';
                    PlaceNQueens(col+1);
                }
                chessBoard[row][col] = '.';
            }
        }

        int GetNumOfWays()
        {
            return numWays;
        }

        vector<vector<string>> GetResultVector()
        {
            return res;
        }
};

class Solution
{
    public:
        vector<vector<string>> solveNQueens(int n)
        {
            NQueen nQueen(n);
            nQueen.PlaceNQueens(0);
            return nQueen.GetResultVector();
        }
};

int nQueen(int n)
{
    NQueen nQueen(n);
    nQueen.PlaceNQueens(0);
    return nQueen.GetNumOfWays();
}

int main(void)
{
    cout << nQueen(4) << endl;
    return 0;
}