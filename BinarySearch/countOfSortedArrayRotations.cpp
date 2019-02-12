# include <iostream>

using namespace std;

int findRotationCount(int Arr[], int n)
{
    int Low = 0, High = n - 1, Mid;
//The underlying principle is that there will be one such element in the array called a pivot element whose previous and
//next element will be greater than the pivot element.
      while(Low <= High)
        {
            if(Arr[Low] <= Arr[High]) //Check if array is already sorted.
              {
                  return Low;
              }
          Mid = (Low + High) / 2;
          int Next = (Mid + 1) % n; //Next Element Will Be (Mid + 1)%n. Calculating remainder is necessary if the last
                                    //element is Mid, thus Mid + 1 will go out of bounds of the array. Thus, it is
                                    //necessary to calculate remainder with the size of the array.
          int Prev = (Mid + n - 1) % n; //Previous Element Will Be  (Mid + n - 1) and cannot be Mid - 1 becuase if the
                                        //Middle Element is A[0] , then A[-1] will be an invalid expression.

            if(Arr[Mid] <= Arr[Next] && Arr[Mid] <= Arr[Prev]) //Check if Arr[Mid] is the pivot element.
              {
                  return Mid;
              }
            else if(Arr[Mid] <= Arr[High]) //Check if Arr[Mid] is a part of the sorted right half of the array.
              {
                  High = Mid - 1;
              }
            else if(Arr[Mid] >= Arr[Low]) //Check if Arr[Mid] is a part of the sorted left half of the array.
              {
                  Low = Mid + 1;
              }
        }
    return -1;
}

int main(void)
{
  int Array[] = {31, 38, 5, 8, 10, 12, 15, 22, 23, 28};
  int Size = sizeof(Array) / sizeof(Array[0]);
  int Count = findRotationCount(Array, Size);
  cout << "\nArray Is Rotated " << Count << " time(s) after sorting.\n" << endl;
  return 0;
}
