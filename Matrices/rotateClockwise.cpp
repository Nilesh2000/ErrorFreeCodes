/*
A program to rotate a 2-dimensional matrix in the clockwise dierection.

If it is a square matrix, it can be transposed in-place.
Otherwise we will have to allocate extra memory.

Approach:
Transpose the matrix in-place
Reverse each row of the matrix in-place

Time Complexity : O(n^2)
Space Complexity : O(n)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Function to print the matrix
void printMatrix(vector<vector<int>> matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

void transposeMatrix(vector<vector<int>> &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
        for (int j = i + 1; j < matrix[i].size(); j++)
            swap(matrix[i][j], matrix[j][i]);
}

void rotateClockwise(vector<vector<int>> &matrix)
{
    transposeMatrix(matrix);

    int n = matrix.size();
    for (int i = 0; i < n; i++)
        reverse(matrix[i].begin(), matrix[i].end());

    printMatrix(matrix);
}

//Driver function
int main(void)
{
    vector<vector<int>> Mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    printMatrix(Mat);

    cout << "\nMatrix after rotating in clockwise dierection:-\n";
    rotateClockwise(Mat);

    return 0;
}
//End of program
