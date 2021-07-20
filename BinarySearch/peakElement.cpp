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
int findPeakIndex(int Arr[], int n, int Low, int High)
{
  int Mid = Low + (High - Low) / 2;

  if ((Mid == 0 || Arr[Mid] >= Arr[Mid - 1]) && (Mid == n - 1 || Arr[Mid] <= Arr[Mid + 1]))
    return Mid;
  else if (Arr[Mid] < Arr[Mid - 1] && Mid > 0)
    findPeakIndex(Arr, n, 0, Mid - 1);
  else
    findPeakIndex(Arr, n, Mid + 1, High);
}

int main(void)
{
  int n;
  cout << "\nEnter the size of the array : ";
  cin >> n;
  int Arr[n];
  cout << "Enter the elements of the array : ";
  for (int i = 0; i < n; i++)
  {
    cin >> Arr[i];
  }
  int Index = findPeakElement(Arr, n, 0, n - 1);
  cout << "\nIndex of peak element is : " << Index << " and the element is : " << Arr[Index];
  return 0;
}
