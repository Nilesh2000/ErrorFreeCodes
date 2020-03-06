//A program to print the fibonnaci sequence using recursion with memoization.
# include <iostream>

using namespace std;

int F[51]; //A globally declared array to store fibonnaci values for any given n. Initially all elements are initialized to -1 which denotes that they have
           //not yet been computed.

int Fib(int n)
{
    if(n <= 1)
      return n;

    if(F[n] != -1)
      return F[n];

    F[n] = Fib(n - 1) + Fib(n - 2);
    return F[n];
}

int main(void) //Driver function
{
    int n;
    cout << "\nEnter the value of n : ";
    cin >> n;
    for(int i = 0 ; i < 51 ; i++)
    {
        F[i] = -1;
    }
    int Res = Fib(n);
    cout << Res;
    return 0;
}
//End of program
