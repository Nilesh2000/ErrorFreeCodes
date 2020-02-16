#include <stdio.h>

int binarySearch(int Arr[], int n, int x)
{
  int Low = 0, High = n - 1, Mid;
  while (Low <= High)
  {
    Mid = (Low + High) / 2;
    if (x == Arr[Mid])
    {
      return Mid;
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
  return -1;
}

void displayIndex(int Flag)
{
  if (Flag != -1)
  {
    printf("\nElement Found At Index %d.", Flag);
  }
  else
  {
    printf("\nElement Not Found.\n");
  }
}

void main()
{
  int Array[] = {19, 22, 24, 47, 47, 53, 61};
  int Size = sizeof(Array) / sizeof(Array[0]), Search;
  int firstSearch = 53, secondSearch = 92;
  int firstStatus = binarySearch(Array, Size, firstSearch);
  int secondStatus = binarySearch(Array, Size, secondSearch);
  displayIndex(firstStatus);
  displayIndex(secondStatus);
}
