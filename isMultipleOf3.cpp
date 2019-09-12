//A program to check if a number is a multiple of 3.
# include <iostream>

using namespace std;

int isMultipleOf3(int n)
{
    if(n < 0)
      n = -n;
    if(n == 0)
      return 1;
    if(n == 1)
      return 0;

    int oddCount, evenCount;
    oddCount = evenCount = 0;
    while(n)
    {
      //Here n is converted to binary
        if(n & 1) //If the odd bit is set, increment odd counter.
          oddCount++;
        if(n & 2) //If even bit is set, increment even counter.
          evenCount++;
        n = n >> 2; //Right shift by two bits
    }
    return isMultipleOf3(abs(oddCount - evenCount));
}

int main(void)
{
    int n = 24;
    if(isMultipleOf3(n) == 1)
      cout << "\nMultiple of 3.";
    else
      cout << "\nNot a multiple of 3.";
    return 0;
}
