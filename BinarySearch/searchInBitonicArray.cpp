/*
Program to search for an element in a bitonic array.

APPROACH
Find the bitonic index in the given array, i.e the index of the largest element in the given bitonic array.
If the element to be searched is equal to the element at the bitonic index then print the index of the bitonic point.
If the element to be searched is greater than the element at a bitonic index then the element does not exist in the array.
If the element to be searched is less than the element at a bitonic index then search for the element in both halves of the array by implementing order agnostic binary search.

If the search key occurs more than once, return the minimum index.

Time Complexity : O(log n)
Space Complexity : O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

int ascendingBinarySearch(vector<int> V, int Low, int High, int x)
{
    if (Low <= High)
    {
        int Mid = Low + (High - Low) / 2;

        if (x == V[Mid])
            return Mid;

        else if (x > V[Mid])
            return ascendingBinarySearch(V, Mid + 1, High, x);

        else if (x < V[Mid])
            return ascendingBinarySearch(V, Low, Mid - 1, x);
    }
    return -1;
}

int descendingBinarySearch(vector<int> V, int Low, int High, int x)
{
    if (Low <= High)
    {
        int Mid = Low + (High - Low) / 2;

        if (x == V[Mid])
            return Mid;

        else if (x > V[Mid])
            return descendingBinarySearch(V, Low, Mid - 1, x);

        else if (x < V[Mid])
            return descendingBinarySearch(V, Mid + 1, High, x);
    }
    return -1;
}

int bitonicIndex(vector<int> V)
{
    int n = V.size();
    int Low = 1, High = n - 2;

    while (Low <= High)
    {
        int Mid = Low + (High - Low) / 2;

        if (V[Mid] < V[Mid - 1])
            High = Mid - 1;

        else if (V[Mid] < V[Mid + 1])
            Low = Mid + 1;

        else
            return Mid;
    }
    return -1;
}

int searchInBitonicArray(vector<int> V, int x)
{
    int n = V.size();
    int bitonicInd = bitonicIndex(V);

    if (x > V[bitonicInd])
        return -1;

    if (x == V[bitonicInd])
        return bitonicInd;

    else if (x < V[bitonicInd])
    {
        int Pos = ascendingBinarySearch(V, 0, bitonicInd - 1, x);
        if (Pos != -1)
            return Pos;

        Pos = descendingBinarySearch(V, bitonicInd + 1, n - 1, x);
        if (Pos != -1)
            return Pos;
    }
    return -1;
}

int main(void)
{
    vector<int> V = {10, 20, 35, 40, 50, 30, 20};
    int x = 30;

    cout << searchInBitonicArray(V, x);

    return 0;
}
