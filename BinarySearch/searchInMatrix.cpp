// Program to Search in a row wise and column wise sorted matrix

// ALGORITHM:

// The simple idea is to remove a row or column in each comparison until an element is found. Start searching from the top-right corner of the matrix. There are three possible cases.

// The given number is greater than the current number: This will ensure that all the elements in the current row are smaller than the given number as the pointer is already at the right-most elements and the row is sorted. Thus, the entire row gets eliminated and continues the search for the next row. Here, elimination means that a row needs not be searched.

// The given number is smaller than the current number: This will ensure that all the elements in the current column are greater than the given number. Thus, the entire column gets eliminated and continues the search for the previous column, i.e. the column on the immediate left.

// The given number is equal to the current number: This will end the search.

#include <iostream>
using namespace std;

int searchInSortedMatrix(int Arr[3][3], int n, int Search)
{
    int i = 0, j = n - 1;
    int Smallest = Arr[0][0], Largest = Arr[n - 1][n - 1];

    if (Search < Smallest || Search > Largest)
    {
        return -1;
    }

    while (i < n && j >= 0)
    {
        if (Arr[i][j] == Search)
        {
            return 1;
        }
        else if (Arr[i][j] > Search)
        {
            j--;
        }
        else if (Arr[i][j] < Search)
        {
            i++;
        }
    }

    return -1;
}
int main(void)
{
    int Mat[3][3] = {{10, 20, 30}, {15, 25, 35}, {27, 29, 37}};
    int Size = 3;
    int Search = 25;
    int searchStatus = searchInSortedMatrix(Mat, Size, Search);
    cout << searchStatus;
    return 0;
}
