#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<string> &board, int row, int col, int n)
{
    // check column
    for (int i = 0; i < row; i++)
        if (board[i][col] == 'Q')
            return false;

    // check left upper diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q')
            return false;

    // check right upper diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 'Q')
            return false;

    return true;
}

void nQueens(vector<string> &board, int row, int n, vector<vector<string>> &ans)
{
    if (row == n)
    {
        ans.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, row, col, n))
        {
            board[row][col] = 'Q';
            nQueens(board, row + 1, n, ans);
            board[row][col] = '.'; // backtrack
        }
    }
}

int main()
{
    int n = 4;
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> ans;

    nQueens(board, 0, n, ans);

    for (auto &solution : ans)
    {
        for (auto &row : solution)
            cout << row << endl;
        cout << endl;
    }

    return 0;
}
