/*
Given an integer n, return the number of trailing zeroes in n !.
Note that n ! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1

APPROACH 1:
1. Calculate the factorial of n
2. Repeatedly divide n! by 10 unless n%10 does not equal 0. Increment count at each iteration
3. Return the value of count.

This approach may cause overflow for even slighly bigger numbers because the factorial of even a slightly small number is a big number.

APPROACH 2:
1. We notice that we get a trailing zero only if there is a pair of 2*5 in the factorial.
2. That is, if we can represent the 2's and 5's in the factorial as 2^x * 5^y and y < x, then number of trailing zeroes will be y.
3. However, we do not have to necessarily calculate the power of number 2.
4. This is because every second number will be a multiple of 2 and only every fifth number will be a multiple of 5.
5. To calculate the power of 5, floor(n/5).
6. But there is an anamoly here.
7. If we take n=28, then multiples of 5 will be 5,10,15,20,25, and here 25 contributes 2 5's.
8. Similarly, if n=128, 125 will contribute 3 5's
9. Thus, the formula becomes n/5 + n/25 + n/125 +....

Time Complexity : O(log5N)
Space Complexity : O(1)
*/

#include <iostream>
using namespace std;

int trailingZeroes(int n)
{
    int count = 0;
    while (n != 0)
    {
        int tmp = n / 5;
        count += tmp;
        n = tmp;
    }
    return count;
}

int main(void)
{
    int n = 120;
    cout << trailingZeroes(n);
    return 0;
}
