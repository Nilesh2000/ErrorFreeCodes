//Header Files
# include <iostream>

using namespace std;

int main(void) //Driver Function
{
    long long n, Sum = 0;
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
    Sum += (n - i) * i; //Incrementing sum by number of wrong possible guesses
    cout << Sum + n << endl; //Adding n to sum the correct answer
    return 0;
}
//Can also be achieved in O(1) time if the (n * i) - i is computed using math formulas
//https://codeforces.com/blog/entry/6545?locale=en
//End Of Program
