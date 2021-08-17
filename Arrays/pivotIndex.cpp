/*
Given an array of integers nums, calculate the pivot index of this array.

Calculate the sum of the array
Set leftSum=0
Traverse array again and on each iteration check if leftSum==arraySum before performing arraySum-=Arr[i].
Increment leftSum by Arr[i] after each if statement

Time Complexity : O(n)
Space Complexity : O(1)
*/

#include <iostream>
using namespace std;

int equiliburumIndex(int Arr[], int n)
{
  int arraySum = 0, leftSum = 0;
  for (int i = 0; i < n; i++)
    arraySum += Arr[i];
  for (int i = 0; i < n; i++)
  {
    arraySum -= Arr[i];
    if (leftSum == arraySum)
    {
      return i;
    }
    leftSum += Arr[i];
  }
  return -1;
}

int main(void)
{
  int Arr[] = {1, 7, 3, 6, 5, 6};
  int n = sizeof(Arr) / sizeof(Arr[0]);

  int Index = equiliburumIndex(Arr, n);
  if (Index != -1)
    cout << Arr[Index] << " is the equiliburum element of the array.";
  else
    cout << "Equiliburum index does not exist for the array.";
}
