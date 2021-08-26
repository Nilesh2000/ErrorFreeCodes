/*
Given an n*n chessboard, place n queens on the chessboard such that

1. Every row must have 1 queen
2. Every column must have 1 queen
3. No two queens should attack each other

APPROACH 1 & 2:
https://www.youtube.com/watch?v=i05Ju7AftcM&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=60&ab_channel=takeUforward

Refer https://leetcode.com/problems/n-queens/discuss/19808/Accepted-4ms-c%2B%2B-solution-use-backtracking-and-bitmask-easy-understand for isSafe() method

APPROACH 2 uses hashing to check if the given square is under attack or not.
It is a classical space-time tradeoff solution
*/

#include <iostream>
#include <vector>

using namespace std;

bool isSafe(int row, int col, vector<string> board, int n)
{
    int i, j;

    // Check if the row has a queen
    for (i = col; i >= 0; i--)
    {
        if (board[row][i] == 'Q')
            return false;
    }

    // Check if the 45° diagonal has a queen
    i = row, j = col;
    while (i >= 0 && j >= 0)
    {
        if (board[i][j] == 'Q')
            return false;
        i--;
        j--;
    }

    // Check if the -45° diagonal has a queen
    i = row, j = col;
    while (i < n && j >= 0)
    {
        if (board[i][j] == 'Q')
            return false;
        i++;
        j--;
    }

    return true;
}

void solveNQueens1(int col, vector<string> board, vector<vector<string>> &ans, int n)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {
            board[row][col] = 'Q';
            solveNQueens1(col + 1, board, ans, n);
            board[row][col] = '.';
        }
    }
}

void solveNQueens2(int col, vector<string> board, vector<int> leftRow, vector<int> lowerDiagonal, vector<int> upperDiagonal, vector<vector<string>> &ans, int n)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0)
        {
            leftRow[row] = 1;
            lowerDiagonal[row + col] = 1;
            upperDiagonal[n - 1 + col - row] = 1;
            board[row][col] = 'Q';
            solveNQueens2(col + 1, board, leftRow, lowerDiagonal, upperDiagonal, ans, n);
            leftRow[row] = 0;
            lowerDiagonal[row + col] = 0;
            upperDiagonal[n - 1 + col - row] = 0;
            board[row][col] = '.';
        }
    }
}

int main(void)
{
    int n = 4;

    vector<vector<string>> ans1;
    string str(n, '.');      // str signifies a empty row of the board
    vector<string> board(n); // board signifies one board

    // Initially set all rows of the board to be empty
    for (int i = 0; i < n; i++)
        board[i] = str;

    solveNQueens1(0, board, ans1, n);

    cout << "APPROACH 1:\n";
    for (int i = 0; i < ans1.size(); i++)
    {
        for (int j = 0; j < ans1[i].size(); j++)
        {
            cout << "[ ";
            cout << ans1[i][j];
            cout << " ]";

            cout << "\n";
        }
        cout << '\n';
    }

    vector<int> leftRow(n, 0);
    vector<int> lowerDiagonal(2 * n - 1, 0);
    vector<int> upperDiagonal(2 * n - 1, 0);
    vector<vector<string>> ans2;

    solveNQueens2(0, board, leftRow, lowerDiagonal, upperDiagonal, ans2, n);

    cout << "APPROACH 2:\n";
    for (int i = 0; i < ans2.size(); i++)
    {
        for (int j = 0; j < ans2[i].size(); j++)
        {
            cout << "[ ";
            cout << ans2[i][j];
            cout << " ]";

            cout << "\n";
        }
        cout << '\n';
    }
}
