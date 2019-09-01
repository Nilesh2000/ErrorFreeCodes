/*
Given an integer n, return the length of the longest consecutive run of 1s in its binary representation.
For example, given 156, you should return 3.
*/
# include <iostream>

using namespace std;

int numOfconsecutiveOnes(int n)
{
    int Count = 0, Max = 0;
    while(n >= 1)
    {
        int Rem = n % 2;
        if(Rem == 1)
          Count++;
        else
        {
          Max = max(Count, Max);
          Count = 0;
        }
        n /= 2;
    }
    return max(Count, Max);
}

int main(void)
{
    int Num;
    cin >> Num;
    cout << numOfconsecutiveOnes(Num);
    return 0;
}
//End of program
