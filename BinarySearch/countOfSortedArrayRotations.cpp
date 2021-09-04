/*
Consider an array of distinct numbers sorted in increasing order. 
The array has been rotated (clockwise) k number of times. 
Given such an array, find the value of k.

The idea here is to find the smallest element in the array.
The index of the smallest element will be the number of times the array was rotated.

A rotated sorted array can also be thought of as two sorted arrays which are appened together.
The pivot element will be the largest element
[0...pivot] - Sorted in increasing order
[pivot...pivot+1] - Sorted in decreasing order
[pivot+1...n-1] - Sorted in increasing order

Time Complexity : O(log n)
Space Complexity : O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

int findRotationCount(vector<int> V)
{
  int n = V.size();
  int Low = 0, High = n - 1;

  while (Low <= High)
  {
    int Mid = Low + (High - Low) / 2;

    // There can only be 1 index in the array where V[Mid]<V[Mid-1].
    // That element at tha index will be the smallest element in the array.
    if (Mid > Low && V[Mid] < V[Mid - 1])
      return Mid;

    // There can only be 1 index in the array where V[Mid] > V[Mid+1].
    // That index will be the largest element in the array
    // Then, Mid+1 will be the index of the smallest element
    if (Mid < High && V[Mid] > V[Mid + 1])
      return Mid + 1;

    // If this is true, it indicates that the array is rotated and we have to search towards the left
    if (V[Mid] <= V[Low])
      High = Mid - 1;

    else
      Low = Mid + 1;
  }

  // The array was not rotated or rotated n times
  return 0;
}

int main(void)
{
  vector<int> V = {31, 38, 5, 8, 10, 12, 15, 22, 23, 28};
  cout << findRotationCount(V);
  return 0;
}
