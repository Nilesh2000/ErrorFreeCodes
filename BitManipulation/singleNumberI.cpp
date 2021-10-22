/*
Given an array of integers, in which every element appears twice except for one. 
Find that element that appears once in array.

APPROACH 1:
1. Store the frequency of each the array elements in a hash map.
2. Iterate through the hash map and check which element occurs only once

Time Complexity : O(N)
Space Complexity : O(N)

APPROACH:
1. The logic here is that the XOR of a number with itself is 0.
2. And the XOR of a number with 0 is the number itself.
3. So, XOR all the array elements. The result will be the element occuring once in the array

Time Complexity : O(N)
Space Complexity : O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int> V)
{
  int n = V.size();
  int singleNum = 0;

  for (auto num : V)
    singleNum = singleNum ^ num;

  return singleNum;
}

int main(void)
{
  vector<int> V = {22, 13, 10, 13, 22};
  cout << singleNumber(V);
  return 0;
}
