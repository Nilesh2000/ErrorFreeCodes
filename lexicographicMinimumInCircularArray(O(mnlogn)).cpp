//Program to find the smallest lexicographic string in a circular array.
//A circular array means that rotations are allowed.
//Time Complexity for sorting is O(n logn)
//Time complexity for string comparison is O(m) where m is the length of the longer string.
//Thus, total time complexity is O(m n logn)
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(void)
{
  string str;
  cout << "\nEnter a string : ";
  cin >> str;
  int n = str.length();
  string Arr[n];
  string concat = str + str;
  for (int i = 0; i < n; i++)
    Arr[i] = concat.substr(i, n);
  sort(Arr, Arr + n);
  cout << Arr[0];
  return 0;
}
