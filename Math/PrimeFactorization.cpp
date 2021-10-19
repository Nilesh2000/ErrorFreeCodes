/*
Given a positve integer N, return the prime factorization of N.

APPROACH:-
1. Iterate from i=2 i=sqrt(N). Increment i by 1.
2. While N%i==0
    2.1 Push i into the result vector
    2.2 Set N = N / i
3. If the prime factor of N is greater than sqrt(N), then push N into the vector.
4. Return the result vector.

EXAMPLE:
Input : N = 24
Output : [2,2,2,3] 

Input : N = 10
Output : [2,5] 
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> primeFactorization(int N)
{
    vector<int> primes;

    for (int i = 2; i <= sqrt(N); i++)
    {
        while (N % i == 0)
        {
            primes.push_back(i);
            N = N / i;
        }
    }

    if (N > 1)
        primes.push_back(N);

    return primes;
}

int main(void)
{
    int N = 404;
    vector<int> V = primeFactorization(N);

    for (auto num : V)
        cout << num << " ";

    return 0;
}
