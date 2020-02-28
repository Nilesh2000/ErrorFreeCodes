//Longest Common Prefix In An Array of Strings Using Word-By-Word Matching

// The logic here is to assume that the first element in the array is the prefix and then traverse the remaining elements of the array to check if they contain the same charcters as that of the prefix.

#include <iostream>
#include <string.h>
using namespace std;
string longestCommonPrefixUtil(string Str1, string Str2)
{
  int strLen1 = Str1.length();
  int strLen2 = Str2.length();
  string Result = "";
  for (int i = 0, j = 0; i < strLen1 && j < strLen2; i++, j++)
  {
    if (Str1[i] != Str2[j])
    {
      break;
    }
    Result.push_back(Str1[i]);
  }
  return Result;
}
string longestCommonPrefix(string Arr[], int numOfStrings)
{
  string prefixStr = Arr[0];
  for (int i = 1; i < numOfStrings; i++)
  {
    prefixStr = longestCommonPrefixUtil(prefixStr, Arr[i]);
  }
  return prefixStr;
}
int main(void)
{
  int n;
  cout << "\nEnter number of strings : ";
  cin >> n;
  string Arr[n];
  cout << "\n";
  for (int i = 0; i < n; i++)
  {
    cout << "String " << i + 1 << " : ";
    cin >> Arr[i];
  }
  string Ans = longestCommonPrefix(Arr, n);
  if (Ans.length())
  {
    cout << "\nThe longest common prefix is : " << longestCommonPrefix(Arr, n);
  }
  else
  {
    cout << "\nNo common prefix in the strings.";
  }
  return 0;
}
