/*
Peak element is the element which is not smaller than its neighbours.
In an increasing array, last element is peak element.
In a decreasing array, first element is peak element.
In an array with all elements are same, every element is a peak element.
Time Complexity : O(log n)
Use a divide and conquer algorithm.

Why do we use Binary Search in an Unsorted Algorithm Here?
https://leetcode.com/problems/find-peak-element/discuss/50232/Find-the-maximum-by-binary-search-(recursion-and-iteration)
*/

#include <iostream>
using namespace std;

int findPeakIndex(int Arr[], int n)
{
  if (n == 1)
    return 0;

  if (Arr[0] > Arr[1])
    return 0;
  if (Arr[n - 1] > Arr[n - 2])
    return n - 1;

  int Low = 1, High = n - 2;

  while (Low <= High)
  {
    int mid = Low + (High - Low) / 2;
    if (Arr[mid] > Arr[mid - 1] && Arr[mid] > Arr[mid + 1])
      return mid;
    else if (Arr[mid] < Arr[mid - 1])
      High = mid - 1;
    else if (Arr[mid] < Arr[mid + 1])
      Low = mid + 1;
  }

  return -1;
}

int main(void)
{
  int Arr[] = {1, 2, 3, 2};
  int n = sizeof(Arr) / sizeof(Arr[0]);
  int Index = findPeakIndex(Arr, n);
  cout << "\nIndex of peak element is " << Index << " and the element is " << Arr[Index];
  return 0;
}
