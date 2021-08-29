/*
Program to search an element in a matrix:-
1. All rows are sorted in ascending order from left to right
2. The first element of each row is greater than the last element of the previous row


APPROACH:
Treat the matrix as an ordered list.
For instance, if we were to convert the matrix to a 1D array, then the position of each element would be defined (row * numOfCols) + col.
For instance if A[0][0] is 1 and A[1][2]=7 in a sqaure matrxi where n=3, then their position in an array will be:-
[0*3]+0 = 0th index
[1*3]+2 = 5th index

Perform binary search as if you were performing it on a sorted 1D array

Time Complexity : O(log(MN))
Space Complexity : O(1)
*/
#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>> nums, int k)
{
    int numRows = nums.size();
    int numCols = nums[0].size();

    int begin = 0, end = numRows * numCols - 1;

    while (begin <= end)
    {
        int mid = begin + (end - begin) / 2;
        int midVal = nums[mid / numCols][mid % numCols];

        if (midVal == k)
            return true;

        else if (midVal < k)
            begin = mid + 1;
        else
            end = mid - 1;
    }
    return false;
}

int main(void)
{
    vector<vector<int>> nums = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int k = 3;
    cout << searchMatrix(nums, k);
    return 0;
}
