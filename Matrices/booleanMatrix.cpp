// Given a boolean matrix mat[M][N] of size M X N, modify it such that if a matrix cell mat[i][j] is 1(or true) then make all the cells of ith row and jth column as 1.

/*
Algorithm :-
1) Create two temporary arrays row[M] and col[N]. Initialize all values of row[] and col[] as 0.
2) Traverse the input matrix mat[M][N]. If you see an entry mat[i][j] as true, then mark row[i] and col[j] as true.
3) Traverse the input matrix mat[M][N] again. For each entry mat[i][j], check the values of row[i] and col[j]. If any of the two values (row[i] or col[j]) is true, then mark mat[i][j] as true.
*/
#include <iostream>
#define R 3
#define C 4

using namespace std;

//Function to print the matrix
void printMatrix(bool Arr[R][C])
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cout << Arr[i][j] << " ";
    }
    cout << "\n";
  }
}

void modifyMatrix(bool Mat[R][C])
{
  bool row[R] = {false}, col[C] = {false};
  for (int i = 0; i < R; i++)
  {
    for (int j = 0; j < C; j++)
    {
      if (Mat[i][j] == 1)
      {
        row[i] = 1;
        col[j] = 1;
      }
    }
  }

  for (int i = 0; i < R; i++)
  {
    for (int j = 0; j < C; j++)
    {
      if (row[i] == 1 || col[j] == 1)
      {
        Mat[i][j] = 1;
      }
    }
  }
}

int main(void)
{
  bool Arr[R][C] = {{1, 0, 0, 1},
                    {0, 0, 1, 0},
                    {0, 0, 0, 0}};
  modifyMatrix(Arr);
  printMatrix(Arr);
  return 0;
}
//End of program
