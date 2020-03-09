// A program to traverse a matrix in zigzag way.
#include <iostream>
using namespace std;

#define row 3
#define col 6

void zigzagPrint(int r, int c, int Mat[row][col])
{
  int evenRow = 0; // Start from the first row
  int oddRow = 1;  // Start from the second row

  while (evenRow < r)
  {
    for (int i = 0; i < c; i++) //Print the even numbered rows
      cout << Mat[evenRow][i] << " ";

    evenRow += 2;

    if (oddRow < r)
    {
      for (int i = c - 1; i >= 0; i--) //Print the odd numbered rows
      {
        cout << Mat[oddRow][i] << " ";
      }
    }
    oddRow += 2;
  }
}

void printMatrix(int Arr[row][col])
{
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      cout << Arr[i][j] << "\t";
    }
    cout << "\n";
  }
}

int main(void)
{

  int Mat[row][col] = {{1, 2, 3, 4, 5, 6}, {7, 8, 9, 10, 11, 12}, {13, 14, 15, 16, 17, 18}};

  printMatrix(Mat);
  cout << "\nMatrix after zigzag   traversal : ";
  zigzagPrint(row, col, Mat);
  return 0;
}
