#include <iostream>

using namespace std;

int firstAndLastOccurence(int Arr[], int n, int x, bool firstSearch)
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

void displayIndex(int Flag)
{
  if (Flag != -1)
  {
    cout << "\nFirst / Last Occurence Of Element Found At Index " << Flag << endl;
  }
  else
  {
    cout << "\nElement Not Found.\n";
  }
}

int main(void)
{
  int Array[] = {1, 1, 3, 3, 5, 5, 5, 5, 5, 9, 9, 11};
  int Size = sizeof(Array) / sizeof(Array[0]), Search;
  int firstSearch = 5, secondSearch = 13;
  int firstStatus = firstAndLastOccurence(Array, Size, firstSearch, true);
  int secondStatus = firstAndLastOccurence(Array, Size, firstSearch, false);
  int Status = firstAndLastOccurence(Array, Size, secondSearch, true);
  displayIndex(firstStatus);
  displayIndex(secondStatus);
  displayIndex(Status);
}
