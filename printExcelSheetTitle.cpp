#include <iostream>
#include <string.h>
#include <algorithm>
#define MAX 50

using namespace std;

void printString(int n)
{
  char Str[MAX]; // To store result (Excel column name)
  int i = 0;     // To store current index in Str which is result

  while (n > 0)
  {
    // Find remainder
    int Rem = n % 26;

    // If remainder is 0, then a 'Z' must be there in output
    if (Rem == 0)
    {
      Str[i++] = 'Z';
      n = (n / 26) - 1;
    }
    else // If remainder is non-zero
    {
      Str[i++] = (Rem - 1) + 'A';
      n = n / 26;
    }
  }
  Str[i] = '\0';

  // Reverse the string and print result
  reverse(Str, Str + strlen(Str));
  cout << Str;
}

// Driver Program
int main(void)
{
  int n;
  cout << "\nEnter the column number : ";
  cin >> n;
  cout << "Excel Column Title : ";
  printString(n);
  return 0;
}
