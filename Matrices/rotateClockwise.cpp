/*
A program to rotate a 2-dimensional matrix in the clockwise dierection.

Approach:
1. Transpose the matrix in-place
2. Reverse each row of the matrix in-place

If it is a square matrix, it can be transposed in-place.
Otherwise we will have to allocate extra memory.

Time Complexity : O(n^2)
Space Complexity : O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printMatrix(vector<vector<int>> M)
{
    for (vector<int> V : M)
    {
        cout << "\n";
        for (auto num : V)
            cout << num << " ";
    }
    cout << "\n";
}

// We need to swap only non-diagonal elements in a sqaure matrix
void transposeMatrix(vector<vector<int>> &M)
{
    for (int i = 0; i < M.size(); i++)
        for (int j = i + 1; j < M[i].size(); j++)
            swap(M[i][j], M[j][i]);
}

void rotateClockwise(vector<vector<int>> &M)
{
    transposeMatrix(M);

    int n = M.size();
    for (int i = 0; i < n; i++)
        reverse(M[i].begin(), M[i].end());

    printMatrix(M);
}

int main(void)
{
    vector<vector<int>> M = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    printMatrix(M);
    rotateClockwise(M);

    return 0;
}
