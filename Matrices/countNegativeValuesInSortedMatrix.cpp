/*
Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.

APPROACH 1:
Set count to 0
Iterate over every element of the matrix and increment count by 1 if the matrix element is negative.
Return count.

Time Complexity : O(m * n)
Space Complexity : O(1)

APPROACH 2:
Iterate over each row of the matrix and using binary search calculate the upper bound for -1.
This will return the index of the first element in the row where an element is greater than -1.
This will help us calculate the number of negatives in each row.

NOTE : Since each row is sorted in decreasing order, remember to use V[i].rbegin(), V[i].rend() while calculating upper_bound using binary search.

Time Complexity : O(m * log(n)) or O(n * log(m))
Space Complexity : O(1)

APPROACH 3 :
Start from the bottom left of the matrix.
If the element is negative increment count by (cols - n) and move one row upwards.
If the element is non-negative move one column to the right.

Time Complexity : O(m + n)
Space Complexity : O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

int countNegatives(vector<vector<int>> V)
{
    int rows = V.size();
    int cols = V[0].size();
    int m = rows - 1;
    int n = 0;
    int Count = 0;
    while (m >= 0 && n < cols)
    {
        int Val = V[m][n];
        if (Val < 0)
        {
            Count += (cols - n);
            --m;
        }
        else
            ++n;
    }
    return Count;
}

int main(void)
{
    vector<vector<int>> V = {{4, 3, 2, -1}, {3, 2, 1, -1}, {1, 1, -1, -2}, {-1, -1, -2, -3}};
    cout << countNegatives(V);
    return 0;
}
