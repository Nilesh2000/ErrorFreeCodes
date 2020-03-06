#include <iostream>
using namespace std;
int reverseNumber(int n)
{
  static int Sum = 0;
  if (n == 0)
    return 0;
  int Rem = n % 10;
  Sum = (Sum * 10) + Rem;
  reverseNumber(n / 10);
  return Sum;
}
int main(void)
{
  int n = 2345;
  cout << reverseNumber(n);
  return 0;
}
