#include <iostream>

using namespace std;

int countOfDuplicates(int Arr[], int n, int x, bool firstSearch)
{
  int Low = 0, High = n - 1, Mid, Result = -1;
  while (Low <= High)
  {
    Mid = (Low + High) / 2;
    if (x == Arr[Mid])
    {
      Result = Mid;
      if (firstSearch)
      {
        High = Mid - 1;
      }
      else
      {
        Low = Mid + 1;
      }
    }
    else if (x < Arr[Mid])
    {
      High = Mid - 1;
    }
    else if (x > Arr[Mid])
    {
      Low = Mid + 1;
    }
  }
  return Result;
}

int main(void)
{
  int Array[] = {1, 1, 3, 3, 5, 5, 5, 5, 5, 9, 9, 11};
  int Size = sizeof(Array) / sizeof(Array[0]);
  int dupElement = 5;
  int Low = countOfDuplicates(Array, Size, dupElement, true);
  if (Low != -1)
  {
    int High = countOfDuplicates(Array, Size, dupElement, false);
    cout << "\nCount Of The Element " << dupElement << " is " << High - Low + 1 << ".\n";
  }
  else
  {
    cout << "\nCount Of The Element " << dupElement << " is 0.\n";
  }
  return 0;
}
