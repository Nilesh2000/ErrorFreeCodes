//A program to check for redundant parantheses in an expression
// ((a + b)) has redundant parantheses.
// (a + b) has no redundant parantheses.
// ((a) + b) has redudnant parantheses.
/*
The logic here is to use a stack.
If we encounter anything other than ), we push it to top of the stack.
If we encounter a ), we set a flag to true.
We then pop till the next opening parantheses and check if there exists an operator (+,-,*,/). If an operator exists, it means there is an exprssion inside the sub-expression. We set the flag to true.
If there is no operator and and we encounter a (, it means that there is no expression inside the parantheses and hence there exists a pair of redudndant parantheses.
*/
#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool checkForRedundantParantheses(string Str)
{
  stack<char> S;
  int Len = Str.length();
  for (int i = 0; i < Len; i++)
  {
    if (Str[i] == ')')
    {
      S.pop();
      char Top = S.top();
      bool Flag = true;
      while (Top != '(')
      {
        if (Top == '+' || Top == '-' || Top == '*' || Top == '/')
          Flag = false;
        S.pop();
        Top = S.top();
      }
      if (Flag)
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
  if (checkForRedundantParantheses(Str))
    cout << "The expression consists of redundant parantheses.\n";
  else
    cout << "The expression has no redudant parantheses.\n";
}
