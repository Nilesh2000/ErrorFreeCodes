// A Kaprekar number is a number whose square when divided into two parts and such that sum of parts is equal to the original number and none of the parts has value 0.
/*
Input :  n = 45  
Output : Yes
Explanation : 45^2 = 2025 and 20 + 25 is 45
ALGORITHM : 
-Find square of n and count number of digits in square.
Split square at different positions and see if sum of two parts in any split becomes equal to n.
*/
#include <iostream>
#include <math.h>
using namespace std;
bool isKaprekar(int n)
{
  int squareOfN = n * n;
  int sq_n = squareOfN;
  int countOfDigits = 0;
  while (squareOfN)
  {
    countOfDigits++;
    squareOfN /= 10;
  }
  for (int splitDigit = 1; splitDigit < countOfDigits; splitDigit++)
  {
    int equalPart = pow(10, splitDigit);

    if (equalPart == n)
      continue;

    int Sum = sq_n / equalPart + sq_n % equalPart;

    if (Sum == n)
      return true;
  }
  return false;
}
int main(void)
{
  int n;
  if (isKaprekar(n))
    cout << "Kaprekar Number.";
  else
    cout << "Not a Kaprekar Number.";
  return 0;
}
