/*
Given a floating point integer x and an exponent n, calculate the value of x^n.
Edge Case : Ask interviewer if n can be a negative value as well. Then x^(-n) becomes 1/x^n

Naive Approach:
Iterate from 0 to n-1 and multiply x by itself for each iteration

Time Complexity : O(n)
Space Complexity : O(1)

Optimal Approach:-
Example:-
Calculate 2^10
2^10 = (2*2)^5
= 4^5
= 4 * 4^4
= 4 * (4 * 4)^2
= 4 * (16)^2
= 4 * (16 * 16)^1
= 4 * 256^1
= 1024

Thus, algorithm becomes
Until n=0, (When n is positve)
if [n%2 == 0] -> Base becomes (x*x) and power becomes n/2
if [n%2 == 1] -> Answer becomes x * (x)^n-1

Time Complexity : O(log n)
Space Complexity : O(1)
*/

#include <iostream>
using namespace std;

double myPow(double x, int n)
{
    if (x == 0)
        return 0;

    double ans = 1.0;
    long long nn = n;

    if (nn < 0)
        nn *= -1;

    while (nn)
    {
        if (nn % 2 == 0)
        {
            x *= x;
            nn /= 2;
        }
        else
        {
            ans *= x;
            nn -= 1;
        }
    }

    ans = (n < 0) ? (double)(1.0) / ans : ans;
    return ans;
}

double myPowRecur(double x, int n)
{
    if (x == 0)
        return 0;

    if (n == 0)
        return 1;

    double temp = myPowRecur(x, n / 2);
    if (n % 2 == 0)
        return temp * temp;

    else
    {
        if (n > 0)
            return x * temp * temp;
        else
            return (temp * temp) / x;
    }
}

int main(void)
{
    double x = 2.10000, n = -3;
    cout << myPow(x, n) << '\n';
    cout << myPowRecur(x, n);
    return 0;
}
