// A program to check for duplicate parantheses in an expression.
/*
The logic used is as follows:-
((a+b)) - Has Duplicate parantheses
(a+b+c) - Does not Duplicate paarantheses

We use a stack here.
If we encounter anything other than ), we push it to top of the stack.
If we encounter a ), then we pop it and pop all characaters until we encounter a (.
We count the number of variables popped.
If the count is 0, it means that there exists a pair of duplicate parantheses.
*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool checkForDuplicateParantheses(string Str)
{
  stack<char> S;
  int Len = Str.length();
  for (int i = 0; i < Len; i++)
  {
    if (Str[i] == ')')
    {
      int Counter = 0;
      char Top = S.top();
      S.pop();
      while (Top != '(')
      {
        Counter++;
        Top = S.top();
        S.pop();
      }
      if (Counter < 1)
        return true;
    }
    else
      S.push(Str[i]);
  }
  return false;
}

int main(void)
{
  string Str;
  cout << "\nEnter an expression : ";
  cin >> Str;
  if (checkForDuplicateParantheses(Str))
    cout << "The expression consists of duplicate parantheses.\n";
  else
    cout << "The expression has no duplicate parantheses.\n";
}
