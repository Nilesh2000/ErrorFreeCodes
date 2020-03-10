//A program to check if a number is a power of two.
#include <iostream>

using namespace std;

/*
A number which is a power of two will have only one set bit, which is the leftmost bit.
Thus, n & n-1 will give 0 for a number which is a power of two.
However, this will not work when n=0.
Thus, we use n & (!(n & (n-1))) to check for a power of two.
*/
bool powerOfTwo(int n)
{
  return n && (!(n & (n - 1)));
}

int main(void)
{
  int n;
  cout << "\nEnter a number : ";
  cin >> n;
  if (powerOfTwo(n))
    cout << "yes";
  else
    cout << "no";
  return 0;
}
