#include <iostream>
using namespace std;
int printNum(int n)
{
  static int Sum;
  if (n == 0)
    return 0;
  printNum(n / 10);
  int Rem = n % 10;
  Sum = (Sum * 10) + Rem;
  return Sum;
}

int main(void)
{
  int n;
  n = 1234;
  cout << printNum(1234);
  return 0;
}
