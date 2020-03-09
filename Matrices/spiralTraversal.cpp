// A program to print a matrix in spiral form.
#include <iostream>
using namespace std;

// #define R 4
// #define C 4

#define R 3
#define C 6

void spiralMatrix(int m, int n, int Arr[R][C])
{
  int i, k = 0, l = 0;
  /*
    k - starting row index
    m - ending row index
    l - starting column index
    n - ending row index
    i - Iterator
  */

  while (k < m && l < n)
  {
    for (i = l; i < n; i++) //Print first row from remaining rows
    {
      cout << Arr[k][i] << " ";
    }
    k++; //Increment row count

    for (i = k; i < m; i++) // Print last column from remaining columns
    {
      cout << Arr[i][n - 1] << " ";
    }
    n--; //Decrement column count

    if (k < m) //Check if there are more rows to be printed
    {
      for (i = n - 1; i >= l; i--) //Print last row from remaining rows
      {
        cout << Arr[m - 1][i] << " ";
      }
      m--;
    }

    if (l < n) //Check if there are more columns to be printed
    {
      for (i = m - 1; i >= k; i--) //Print first column from remianing columns
      {
        cout << Arr[i][l] << " ";
      }
      l++;
    }
  }
}

void printMatrix(int Arr[R][C])
{
  for (int i = 0; i < R; i++)
  {
    for (int j = 0; j < C; j++)
    {
      cout << Arr[i][j] << "\t";
    }
    cout << "\n";
  }
}

int main(void)
{
  // int Mat[R][C] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

  int Mat[R][C] = {{1, 2, 3, 4, 5, 6}, {7, 8, 9, 10, 11, 12}, {13, 14, 15, 16, 17, 18}};

  printMatrix(Mat);
  cout << "\nMatrix after spiral traversal : ";
  spiralMatrix(R, C, Mat);
  return 0;
}
//End of program
/*
To print a matrix in anti spiral form,
all we have to do is traverse the matrix in a spiral form and then insert each element during the iteration into a stack.
*/
