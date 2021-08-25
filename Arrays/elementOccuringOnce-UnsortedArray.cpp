// Given a array of integers, in which every element appears twice except for one. Find that element that appears once in array.

/*
APPROACH:
Store all the elements of the array in a hash map.
Iterate through the hash map and check which element occurs only once

Time Complexity : O(N)
Space Complexity : O(N)

APPROACH:
The logic here is that the XOR of a number with itself is 0.
And the XOR of a number with 0 is the number itself.
So, XOR all the array elements. The result will be the element occuring once in the array

Time Complexity : O(N)
Space Complexity : O(1)
*/

#include <iostream>

using namespace std;

int main(void)
{
  int n = 5;
  int Arr[n] = {2, 1, 3, 1, 2};

  int Res = Arr[0];
  for (int i = 1; i < n; i++)
    Res = Res ^ Arr[i];

  cout << "Element occuring once : " << Res << endl;

  return 0;
}
