#include <stdio.h>

int binarySearch(int Arr[], int Low, int High, int x)
{
  if (Low > High)
  {
    return -1;
  }

  int Mid = (Low + High) / 2;
  if (x == Arr[Mid])
  {
    return Mid;
  }
  else if (x > Arr[Mid])
  {
    return binarySearch(Arr, Mid + 1, High, x);
  }
  else if (x < Arr[Mid])
  {
    return binarySearch(Arr, Low, Mid - 1, x);
  }
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
  int firstStatus = binarySearch(Array, 0, Size - 1, firstSearch);
  int secondStatus = binarySearch(Array, 0, Size - 1, secondSearch);
  displayIndex(firstStatus);
  displayIndex(secondStatus);
}
