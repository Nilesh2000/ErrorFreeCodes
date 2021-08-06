// Given an array, find the majority element present in the array.
// A majority element in an array A[] of size n is an element that appears more than n / 2 times(and hence there is at most one such element).

/*
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

using namespace std;

int findMajorityElement(int Arr[], int Size)
{
  int Count = 0, majorityElement;

  for (int i = 0; i < Size; i++)
  {
    if (Count == 0)
      majorityElement = Arr[i];
    if (Arr[i] == majorityElement)
      Count++;
    else
      Count--;
  }

  // Check if the element we have assumed to be the majority element is indeed the majority element
  // That is, check if it occurs more than n/2 times.
  Count = 0;
  for (int i = 0; i < Size; i++)
  {
    if (Arr[i] == majorityElement)
    {
      Count++;
    }
  }

  if (Count > Size / 2)
  {
    return majorityElement;
  }
  return -1;
}

//Driver function
int main(void)
{
  int Arr[] = {3, 3, 4};
  //int Arr[] = {1, 2, 3, 3, 3, 4, 5};
  int n = sizeof(Arr) / sizeof(Arr[0]);
  int majorityElement = findMajorityElement(Arr, n);
  if (majorityElement == -1)
    cout << "\nThere is no majority element.";
  else
    cout << "The majority element is : " << majorityElement;
  return 0;
}
//End of program
