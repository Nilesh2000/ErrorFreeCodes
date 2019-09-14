/*
Given a positve integer, find the sum of digits of the number till the sum becomes a single digit.
*/
# include <iostream>

using namespace std;

int main(void)
{
    int Num, Sum = 0;
    cout << "\nEnter a number : ";
    cin >> Num;
    while(Num != 0)
    {
        int a = Num % 10;
        Sum += a;
        Num /= 10;
    }
    Sum %= 9;
    if(Sum == 0)
      Sum = 9;
    cout << Sum;
    return 0;
}
