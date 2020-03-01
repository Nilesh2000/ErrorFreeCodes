//Program to calculate sum of a digits using recursion
#include <iostream>
using namespace std;
int sumOfDigits(int n)
{
  if (n == 0)
    return 0;
  return (n % 10) + sumOfDigits(n / 10);
}
int main(void)
{
  int n;
  cout << "\nEnter a number : ";
  cin >> n;
  cout << "The sum of the digits is : " << sumOfDigits(n) << "\n";
  return 0;
}
