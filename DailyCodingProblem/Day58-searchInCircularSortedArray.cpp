/*
This problem was asked by Amazon.
An sorted array of integers was rotated an unknown number of times.
Given such an array, find the index of the element in the array in faster than linear time. If the element doesn't exist in the array, return null.
For example, given the array [13, 18, 25, 2, 8, 10] and the element 8, return 4 (the index of 8 in the array).
You can assume all the integers in the array are unique.
*/
# include <iostream>

using namespace std;

int circularArraySearch(int Arr[], int n, int x)
{
  int Low = 0, High = n - 1, Mid;
    while(Low <= High)
      {
        Mid = (Low + High) / 2;
          if(x == Arr[Mid]) //Return Mid if x is found
            {
                return Mid;
            }
          else if(Arr[Mid] <= Arr[High]) //Right Half Of The Array is Sorted
            {
                if(x > Arr[Mid] && x <= Arr[High])
                  {
                      Low = Mid + 1; //Go for searching in the right sorted half.
                  }
                else
                  {
                      High = Mid - 1; //Go towards the left.
                  }
            }
          else if(Arr[Mid] >= Arr[Low]) //Left Half Of The Array is Sorted
            {
                if(x >= Arr[Low] && x < Arr[Mid])
                  {
                      High = Mid - 1; //Go searching in the left sorted half
                  }
                else
                  {
                      Low = Mid + 1; //Go towards right
                  }
            }
      }
  return -1;
}

void displayIndex(int Flag)
{
  if(Flag != -1)
    {
      printf("\nElement Found At Index %d.", Flag);
    }
  else
    {
        printf("\nElement Not Found.\n");
    }
}

int main(void)
{
  int Array[] = {31, 38, 5, 8, 10, 12, 15, 22, 23, 28};
  int Size = sizeof(Array) / sizeof(Array[0]), firstSearch = 8, secondSearch = 29;
  int firstStatus = circularArraySearch(Array, Size, firstSearch);
  int secondStatus = circularArraySearch(Array, Size, secondSearch);
  displayIndex(firstStatus);
  displayIndex(secondStatus);
  return 0;
}
