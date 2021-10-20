/*
Given an integer m, calculate it's nth root

Time Complexity : O(n * log(m * 10^d))
Space Complexity : O(1)
*/

#include <iostream>

using namespace std;

double multiply(double num, int n)
{
    double ans = 1.0;
    for (int i = 1; i <= n; i++)
        ans *= num;
    return ans;
}

double findNthRoot(int m, int n)
{
    double Low = 1.0;
    double High = m, Mid;
    // eps represents the precision we want in our answer
    // 1e-6 means we want the precision to be 5 decimal places
    double eps = 1e-6;

    while (High - Low > eps)
    {
        Mid = (Low + High) / 2.0;
        if (multiply(Mid, n) < m)
            Low = Mid;
        else
            High = Mid;
    }

    return Mid;
}

int main(void)
{
    int m = 16, n = 2;
    cout << findNthRoot(m, n);
    return 0;
}
