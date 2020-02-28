//Program to count the number of zeroes in a number using recursion
//If a number is divsible by 10, then the last digit of that number is 0.
//This is the logic we use in this program.
#include <iostream>
using namespace std;
int countZeroes(int Num)
{
  if (Num == 0)
    return 0;
  else if (Num % 10 == 0)
    return 1 + countZeroes(Num / 10);
  else
    return countZeroes(Num / 10);
}

int main(void)
{
  int n;
  cout << "\nEnter a number : ";
  cin >> n;
  cout << "The number of zeroes is : " << countZeroes(n) << "\n";
  return 0;
}
