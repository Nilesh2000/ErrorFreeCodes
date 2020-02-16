#include <iostream>
#include <string.h>
using namespace std;

int strstr(string s1, string s2)
{
  int strLen = s1.length();
  int subStrLength = s2.length();

  for (int i = 0; i < strLen - subStrLength; i++)
  {
    int j;
    for (j = 0; j < subStrLength; j++)
    {
      if (s1[i + j] != s2[j])
        break;
    }
    if (j == subStrLength)
      return i;
  }
  return -1;
}

int main(void)
{
  string Str, subStr;
  cout << "\nEnter a string : ";
  cin >> Str;
  cout << "Enter the substring : ";
  cin >> subStr;
  int Res = strstr(Str, subStr);
  if (Res != -1)
    cout << "\nSubstring found at index : " << Res;
  else
    cout << "\nSubstring not found.";
  return 0;
}
