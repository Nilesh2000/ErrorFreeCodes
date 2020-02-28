//Longest Common Prefix In An Array of Strings Using Character by Charcter Matching
/*
The logic here is to calculate the minimum length among all strings.
Then, we traverse all strings except the first string only upto the minimum length and check if it matches each character of the first string.
*/

#include <iostream>
#include <string.h>
using namespace std;

int minLength(string Arr[], int n)
{
  int minLen = Arr[0].length();
  for (int i = 1; i < n; i++)
  {
    if (minLen > Arr[i].length())
      minLen = Arr[i].length();
  }
  return minLen;
}

string longestCommonPrefix(string Arr[], int n)
{
  int minLen = minLength(Arr, n);
  char Current;
  string Result;
  for (int i = 0; i < minLen; i++)
  {
    Current = Arr[0][i];
    for (int j = 1; j < n; j++)
    {
      if (Arr[j][i] != Current)
        return Result;
    }
    Result.push_back(Current);
  }
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
/*
This algorithm is better than word by word matching algorithm.
Let us consider [geesk, geek, geez, x]
In the word matching algorithm, the algorithm will terminate only after the last iteration.
Whereas in this case, it will terminate in the firt iteration itself.
*/
