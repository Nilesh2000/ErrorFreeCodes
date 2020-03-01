/*
Program to display the next smallest element for every element of the array.
The logic here is to use a stack.

1) Push the first element to stack.
2) Pick rest of the elements one by one and follow following steps in loop.
….a) Mark the current element as next.
….b) If stack is not empty, then pop an element from stack and compare it with next.
….c) If next is smaller than the popped element, then next is the NSE for the popped element.
….d) Keep popping from the stack while the popped element is greater than next. next becomes the NSE for all such popped elements
3) After the loop in step 2 is over, pop all the elements from stack and print -1 as next element for them.

If we follow the above steps, we may not get the array elements in order.
Instead, we can use a map to display elements in the order in which they were entered.
*/
#include <iostream>
#include <stack>
#include <map>
using namespace std;

void nextSmallestElement(int Arr[], int n)
{
  stack<char> S;
  S.push(Arr[0]);
  map<int, int> M;
  for (int i = 1; i < n; i++)
  {
    if (S.empty())
    {
      S.push(Arr[0]);
    }
    else
    {
      while (!S.empty() && S.top() > Arr[i])
      {
        M[S.top()] = Arr[i];
        S.pop();
      }
    }
    S.push(Arr[i]);
  }

  while (!S.empty())
  {
    M[S.top()] = -1;
    S.pop();
  }

  cout << "Array of next smallest elements is : ";
  for (int i = 0; i < n; i++)
    cout << M[Arr[i]] << " ";
}

// Driver program
int main(void)
{
  int n;
  cout << "\nEnter the size of the array : ";
  cin >> n;
  int Arr[n];
  cout << "Enter the elements of the array : ";
  for (int i = 0; i < n; i++)
    cin >> Arr[i];
  nextSmallestElement(Arr, n);
  cout << "\n";
  return 0;
}
