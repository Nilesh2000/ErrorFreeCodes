#include <iostream>
using namespace std;
bool lucky(int n)
{
    while (n != 0)
    {
        if (n % 10 != 4 && n % 10 != 7)
        {
            return false;
        }
        n /= 10;
    }
    return true;
}
bool almost_lucky(int n)
{
    if (lucky(n)) //Check if it is a lucky number or not
    {
        return true;
    }
    //If not lucky
    for (int i = 2; i * i <= n; ++i) //Run loop from 2 to n (No sense in starting from 1 since and condition will always be false)
                                     //Condition is i*i<=n to reduce time completity of the loop. Thus, n/i has been used in the 
                                     //succeeding if condition.
    {
        if (n % i == 0 && (lucky(i) || lucky(n / i))) //Check if n is divisible by i and then check if i is lucky or n/i is lucky
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    if (almost_lucky(n))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
