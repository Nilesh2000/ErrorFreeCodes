/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's, and return the matrix.
https://www.youtube.com/watch?v=M65xBewcqcI&ab_channel=takeUforward

Approach 1:-
Assuming all integers in the matrix are positve.
Traverse the matrix element by element. If you find a 0, set the whole row and column to -1.
We are setting elements to -1 and not 0 since we might miss out or set some other elements to 0 incase we directly set the rows and columns to 0 in the first iteration.
After traversing the complete matrix, traverse it again and set all -1 to 0.

Time Complexity : O((N*M) * (N+M))
Space Complexity : O(1)

Approach 2:-
Number of rows is m.
Number of columns is n.
Allocate memory for a row array of size m and and a column array of size n.
Iterate through the matrix and check if you find a 0.
If a 0 is found then set then row index and column index of the arrays created corresponding the matrix to 0.

For example, if 0 is found at [0,1], set the 0th index of the row array and 1st index of the column array to be 0.

Then traverse the matrix again. For each entry Mat[i][j], check values of row[i] and col[j]. If any of row[i] or col[j] is 0, set Mat[i][j] to 0.

Time Complexity : O((N*M)+(N*M))
Space Complexity : O(N) + O(M)

Approach 3:-
Create two boolean variables rowFlag and colFlag. Set both to false
Iterate along the first row and check if there exists a 0. If it does set rowFlag to true.
Iterate along the first column and check if there exists a 0. If it does set colFlag to true.

Take the first row of the matrix as a column dummy matrix.
Take the first column of the matrix as row dummy matrix.

Iterate along the m-1 rows and n-1 columns. If there exists a 0 in mat[i][j], set mat[0][j] and mat[i][0] to 0
Then iterate from 1 to m-1 and 1 to n-1 on the matrix and check if mat[i][0] or mat[0][j] equals 0, then set mat[i][j] to 0.
If row_flag or col_flag are true, iterate the first row and first column and set the entire row or column to be 0.

Time Complexity : O((N*M) + (N*M))
Space Complexity : O(1)
*/

#include <iostream>
#define R 3
#define C 3
using namespace std;

void setMatrixZeroes(int Arr[R][C])
{
    // Set rowFlag and colFlag to false initially
    bool rowFlag = false, colFlag = false;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            // Check if there is a 0 in the first row
            if (i == 0 && Arr[i][j] == 0)
                rowFlag = true;

            // Check if there is a 0 in the first column
            if (j == 0 && Arr[i][j] == 0)
                colFlag = true;

            // Check if there is a 0 anywhere other than the first row and first column
            if (Arr[i][j] == 0)
            {
                // Set the corresponding row dummy array and column dummy array index to 0
                Arr[i][0] = 0;
                Arr[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < R; i++)
    {
        for (int j = 1; j < C; j++)
        {
            if (Arr[0][j] == 0 || Arr[i][0] == 0)
            {
                Arr[i][j] = 0;
            }
        }
    }

    // If either rowFlag or colFlag is true, set the corresponding first row or first column to 0
    if (rowFlag == true)
        for (int i = 0; i < C; i++)
            Arr[0][i] = 0;

    if (colFlag == true)
        for (int i = 0; i < R; i++)
            Arr[i][0] = 0;
}

int main(void)
{
    int Arr[R][C] = {{9, 1, 1}, {9, 2, 3}, {3, 1, 0}};
    setMatrixZeroes(Arr);

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << Arr[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
