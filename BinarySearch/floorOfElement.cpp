/*
Given a sorted array and a value x, find the floor of x.
The floor of x is the largest element in array smaller than or equal to x.
Write an efficient function to find floor of x.
*/
#include <iostream>

using namespace std;

int floorOfAnElement(int Arr[], int n, int Num)
{
  int Low = 0, High = n - 1;

  if (Num >= Arr[High])
    return High;

  if (Num < Arr[Low])
    return -1;

  while (Low <= High)
  {
    int Mid = (Low + High) / 2;
    if (Arr[Mid] == Num)
      return Mid;

    else if (Arr[Mid - 1] <= Num && Arr[Mid] > Num && Mid > 0)
      return Mid - 1;

    else if (Arr[Mid] > Num)
      High = Mid - 1;

    else
      Low = Mid + 1;
  }
  return -1;
}

int main(void)
{
  int Arr[] = {1, 2, 4, 7, 9, 13, 17};
  int n = sizeof(Arr) / sizeof(Arr[0]);
  int x1 = 11; //Set x1 as 0 to execute else condition.
  int Index1 = floorOfAnElement(Arr, n, x1);
  if (Index1 == -1)
    cout << "\nFloor of " << x1 << " does not exist in the array.";
  else
    cout << "\nFloor of " << x1 << " is : " << Arr[Index1];
  return 0;
}
