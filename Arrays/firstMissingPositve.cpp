/*
Given an unsorted integer array nums, return the smallest missing positive integer.

OBSERVATION:
An array consiting of elements in range of [1,n] can be stored in an array having indices [0,n-1].

APPROACH:
This problem can solved using the Cyclic Sort Approach.
We place all numbers which are in the range of 0>A[i]<=n at the correct indices such that index of A[i] is A[i]-1.
Then we iterate over the array from [0,n-1] and then return i+1 for the number which is not in its correct position
If all numbers are in the correct position, we return n+1.

Time Complexity : O(N)
Space Complexity : O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

int firstMissingPositve(vector<int> V)
{
    int i = 0;
    int n = V.size();

    while (i < n)
    {
        if (V[i] > 0 && V[i] <= n && V[i] != V[V[i] - 1])
            swap(V[i], V[V[i] - 1]);
        else
            i++;
    }

    for (int i = 0; i < n; i++)
    {
        if (i != V[i] - 1)
            return i + 1;
    }
    return n + 1;
}

int main(void)
{
    vector<int> V = {3, 4, -1, 1};
    vector<int> V = {1, 2, 3, 4};
    cout << firstMissingPositve(V);
    return 0;
}
