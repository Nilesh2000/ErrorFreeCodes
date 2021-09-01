/*
Given an array nums containing n distinct numbers in the range[0, n], return the only number in the range that is missing from the array.

APPROACH:
Perform a cyclic sort since all numbers present in the array are in the range of [0,n]. All index are in the range of [0,n-1] since one number is missing
After sorting the index at which i!=V[i], return i.
If no such index is present, it means that 'n' is missing from the array.

APPROACH:-
XOR all the numbers in the array.
XOR it with the size of the array
XOR it with [0,n-1].

Time Complexity : O(n)
Space Complexity : O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

int findMissing(vector<int> V)
{
    int n = V.size();
    int result = V.size();
    for (int i = 0; i < n; i++)
    {
        result ^= i;
        result ^= V[i];
    }
    return result;
}

int findMissingCyclicSort(vector<int> V)
{
    int i = 0, n = V.size();
    while (i < n)
    {
        if (V[i] != n && i != V[i])
            swap(V[i], V[V[i]]);
        else
            i++;
    }

    for (int i = 0; i < n; i++)
    {
        if (i != V[i])
            return i;
    }
    return n;
}

int main(void)
{
    vector<int> V{4, 3, 1, 2, 0};
    cout << findMissing(V) << '\n';
    cout << findMissingCyclicSort(V);
    return 0;
}
