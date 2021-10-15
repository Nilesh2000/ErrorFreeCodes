/*
Given an array of integers nums, calculate the pivot index of this array.

1. Compute sum of the array.
2. Set leftSum=0
3. Set arraySum-=Arr[i] and check if leftSum==arraySum. Return i if the condition is satisfied.
4. Increment leftSum by Arr[i] after each if statement
5. Return -1 once the loop ends.

Time Complexity : O(n)
Space Complexity : O(1)
*/

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int equiliburumIndex(vector<int> V)
{
  int arraySum = accumulate(V.begin(), V.end(), 0);
  int leftSum = 0;

  for (int i = 0; i < V.size(); i++)
  {
    arraySum -= V[i];

    if (leftSum == arraySum)
      return i;

    leftSum += V[i];
  }

  return -1;
}

int main(void)
{
  vector<int> V = {1, 7, 3, 6, 5, 6};
  cout << equiliburumIndex(V);
  return 0;
}
