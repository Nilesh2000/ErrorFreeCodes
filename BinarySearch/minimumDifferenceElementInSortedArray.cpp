/*
Given a sorted array, find the element in the array which has minimum difference with the given number.

APPROACH 1:
1. Find the ceil and floor of the element in the sorted array.
2. Subtract the key with the floor and ceil respectively.
3. Return the smaller difference.

Time Complexity : O(2*LogN)
Space Complexity : O(1)

APPROACH 2:
1. Use binary search and keep iterating till Low<=High.
2. If Key exists in the sorted array, return 0.
3. Else, once the iteration is completed, return min(Key - V[High], V[Low] - Key)

Time Complexity : O(LogN)
Space Complexity : O(1)

DO CHECK FOR EDGE CASES.
*/

#include <iostream>
#include <vector>

using namespace std;

int minimumDifferenceElement(vector<int> V, int Key)
{
    if (V[0] > Key)
        return V[0] - Key;

    if (V[V.size() - 1] < Key)
        return Key - V[V.size() - 1];

    int n = V.size();
    int Low = 0, High = n - 1;

    while (Low <= High)
    {
        int Mid = Low + (High - Low) / 2;
        if (V[Mid] == Key)
            return 0;
        else if (V[Mid] > Key)
            High = Mid - 1;
        else if (V[Mid] < Key)
            Low = Mid + 1;
    }

    return min(Key - V[High], V[Low] - Key);
}

int main(void)
{
    vector<int> V = {4, 5, 6, 8, 9};
    int Key = 5;
    cout << minimumDifferenceElement(V, Key);
    return 0;
}
