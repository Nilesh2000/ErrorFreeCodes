/*
Given an array, find the majority element present in the array.
A majority element in an array A[] of size n is an element that appears more than n / 2 times (and hence there is at most one such element).

Approach 1:-
Store the frequency of each element in a map or frequency array.
Then iterate through the map and check if any of the elements have a frequency greater than that of n/2. Return that element
Time Complexity : O(n)
Space Complexity : O(n)

Approach 2:-
Moore's Voting Algorithm
This algorithm initially assumes that a majority element is present in the array.
Time Complexity : O(n)
Space Complexity : O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

int findMajorityElement(vector<int> V)
{
  int Count = 0, majorityElement;

  for (auto num : V)
  {
    if (Count == 0)
      majorityElement = num;
    if (num == majorityElement)
      Count++;
    else
      Count--;
  }

  // Check if the element we have assumed to be the majority element is indeed the majority element
  // That is, check if it occurs more than n/2 times.
  Count = 0;
  for (auto num : V)
  {
    if (num == majorityElement)
      Count++;
  }

  if (Count > V.size() / 2)
    return majorityElement;

  return -1;
}

int main(void)
{
  vector<int> V = {3, 3, 4};
  // vector<int> V = {1, 2, 3, 3, 3, 4, 5};

  cout << findMajorityElement(V);
  return 0;
}
