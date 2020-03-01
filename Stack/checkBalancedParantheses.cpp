// Program to check if an expression has duplicate parantheses.
/*
((a+b)) has duplicate parantheses.
(a+b) doesn't have any.
We use a stack to implement this program.
If we encounter a '(', an operator or an operand, we blindly push it onto the stack.
In case we encounter a ')', we first pop it from the top of the stack.
Then, until we keep popping from the stack until we reach a '('. We keep track of the number of charcacters we have popped from the stack.
If the number of characters popped is 0, it means no elements were popped from the stack.
And thus, there exists a pair of duplicate parantheses.
*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool hasDuplicateParantheses(string Str)
{
  stack<char> Stack;
  int strLen = Str.length();
  for (int i = 0; i < strLen; i++)
  {
    if (Str[i] == ')')
    {
      char topOfStack = Str[i];
      Stack.pop();
      int Counter = 0;
      while (topOfStack != '(')
      {
        Counter++;
        char Top = Stack.top();
        Stack.pop();
      }
      if (Counter < 1)
        return true;
    }
    else
      Stack.push(Str[i]);
  }
  return false;
}

int main(void)
{
  string S;
  cout << "\nEnter an expression : ";
  cin >> S;
  if (hasDuplicateParantheses(S))
    cout << "\nThe expression has duplicate parantheses.";
  else
    cout << "The expression does not have any duplicate parantheses.";
}
