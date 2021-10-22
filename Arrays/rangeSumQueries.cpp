/*
Given an array arr of integers of size n. We need to compute the sum of elements from index i to index j. 
The queries consisting of i and j index values will be executed multiple times.

APPROACH 1:
1. Compute the sum of every query.
2. Iterate from V[i] to V[j] and increment sum at each iteration
3. Return Sum

Time Complexity : O(NumQueries * N)
Space Complexity : O(1)

APPROACH 2:
1. Compute the prefix sum of the array
2. For every query, return the value of V[j] - V[i-1]
3. Make sure i is not 0. If it is, return V[j].

Time Complexity : O(1)
Space Complexity : O(N)
*/

#include <iostream>
#include <vector>

using namespace std;

int rangeSumQueries(vector<int> V, int i, int j)
{
    if (i == 0)
        return V[j];

    return V[j] - V[i - 1];
}

vector<int> preCompute(vector<int> V)
{
    int n = V.size();
    vector<int> prefixSum(n);

    prefixSum[0] = V[0];
    for (int i = 1; i < n; i++)
        prefixSum[i] = V[i] + prefixSum[i - 1];
    return prefixSum;
}

int main(void)
{
    vector<int> V = {1, 2, 3, 4, 5};
    vector<int> prefixSum = preCompute(V);

    cout << rangeSumQueries(prefixSum, 1, 3) << "\n";
    cout << rangeSumQueries(prefixSum, 2, 4) << "\n";
    cout << rangeSumQueries(prefixSum, 0, 2) << "\n";

    return 0;
}
