/*
A program to check if a string contains balanced parantheses.

1. The idea here is to use a stack so that we can push into the stack if one of the characters if (,{ or [. And if it is one of ),},], we then check if the stack is empty or not.
2. If the stack is empty, we return false to main().
3. If it is not empty, we then check if the topmost element of the stack forms a pair with one of the types of the closing brackets.
4. If they do form a pair, we pop out the topmost element of the stack and continue to iterate through the string. If they do not form a pair, we return false to the calling environment.
5. If we exit the loop successfully, we then check if the stack is finally empty or not.
6. If it is not empty, we return false, else just return true back to main().

Time Complexity : O(N)
Space Complexity : O(N)
*/

#include <iostream>
#include <stack>

using namespace std;

bool arePair(char opening, char closing)
{
  if (opening == '(' && closing == ')')
    return true;
  if (opening == '{' && closing == '}')
    return true;
  if (opening == '[' && closing == ']')
    return true;
  return false;
}

bool checkBalancedParantheses(string str)
{
  stack<char> S;
  for (char ch:str)
  {
    if (ch == '(' || ch == '{' || ch == '[')
      S.push(ch);
    else
    {
      if (S.empty() || !arePair(S.top(), ch))
        return false;
      else
        S.pop();
    }
  }
  return S.empty() ? true : false;
}

int main(void)
{
  string s = "[{}()]";
  cout << checkBalancedParantheses(s)
  return 0;
}
