#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> board;
vector<vector<int>> bestBoard;

int maxPlaced = 0;
int startRow = -1, startCol = -1;

bool isSafe(int row, int col)
{
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (board[r][c] == 1)
            {
                if (r == row && c == col) continue;
                if (r == row) return false;
                if (c == col) return false;
                if (r + c == row + col) return false;
                if (r - c == row - col) return false;
            }
        }
    }
    return true;
}

void storeBoard()
{
    bestBoard = board;
}

void solve(int row, int placed)
{
    if (placed > maxPlaced)
    {
        maxPlaced = placed;
        storeBoard();
    }

    if (placed == m) return;
    if (row >= n) return;

    // skip the row of the fixed first queen
    if (row == startRow)
    {
        solve(row + 1, placed);
        return;
    }

    // try placing a queen in this row
    for (int col = 0; col < n; col++)
    {
        if (isSafe(row, col))
        {
            board[row][col] = 1;
            solve(row + 1, placed + 1);
            board[row][col] = 0;
        }
    }

    // option to skip this row
    solve(row + 1, placed);
}

void printBoard(const vector<vector<int>> &arr)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << (arr[i][j] ? "Q " : ". ");
        }
        cout << '\n';
    }
}

int main()
{
    cout << "Enter board size (n): ";
    cin >> n;

    cout << "Enter number of candidates (m): ";
    cin >> m;

    cout << "Enter starting candidate position (row col) [1-based]: ";
    cin >> startRow >> startCol;

    startRow--;
    startCol--;

    if (startRow < 0 || startRow >= n || startCol < 0 || startCol >= n)
    {
        cout << "Invalid starting position\n";
        return 0;
    }

    board.assign(n, vector<int>(n, 0));
    bestBoard.assign(n, vector<int>(n, 0));

    // place the fixed first queen
    board[startRow][startCol] = 1;

    solve(0, 1);

    cout << "\nMaximum candidates placed: " << maxPlaced << "\n";
    cout << "One valid arrangement:\n";
    printBoard(bestBoard);

    return 0;
}
