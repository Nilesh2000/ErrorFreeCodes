/*
Given a positve integer N, print all the factors of N.

OBSERVATION:
1) 1 and N are divisors of N.
2) Factors come in pairs.

APPROACH 1:
1. Iterate from 2 to N.
2. Check if N%i is 0.
3. If it is insert it into the vector.

Time Complexity : O(N)

APPROACH 2:
1. The largest factor is N.
2. The second largest factor must be less than or equal to N/2.
3. Thus, we can iterate from 2 to N/2.

Time Complexity : O(N/2)

APPROACH 3:
1. The second largest factor must be less than or equal to N/2.
2. The third largest factor must be less than or equal to N/3.
3. The fourth largest factor must be less than or equal to N/4.
4. At the halfway path, the numbers swap.
5. That is, for some i * X = N, X = N/i
6. Also, i <= N/i. Thus, i^2 <= N. So, i <= sqrt(N).
7. Thus, we have to iterate only from i to sqrt(N). And we have to print only i and N/i.
8. However, if we want to print only the factors of N and if N is a perfect square sqrt(N) will be printed twice.
9. Thus, we iterate only till < sqrt(N).
10. After the loop finishes, we check if N is a perfect sqaure or not

Time Complexity : O(sqrt(N))
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> factorsOfNum(int N)
{
    int i, sqrtN = sqrt(N);
    vector<int> V;
    for (i = 1; i < sqrtN; i++)
    {
        if (N % i == 0)
            V.insert(V.end(), {i, N / i});
    }
    if (N % i == 0)
        V.push_back(i);
    return V;
}

int main(void)
{
    int num = 60;
    vector<int> V = factorsOfNum(num);
    for (auto factor : V)
        cout << factor << " ";
    return 0;
}
