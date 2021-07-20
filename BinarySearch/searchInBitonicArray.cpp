// Program to search for an element in a bitonic array

// ALGOTITHM:
// Find the bitonic point in the given array, i.e the maximum element in the given bitonic array.
// If the element to be searched is equal to the element at the bitonic point then print the index of the bitonic point.
// If the element to be searched is greater than the element at a bitonic point then the element does not exist in the array.
// If the element to be searched is less than the element at a bitonic point then search for the element in both halves of the array using binary search.

#include <iostream>
using namespace std;

int ascendingBinarySearch(int Arr[], int Size, int x)
{
    int Low = 0, High = Size - 1;
    while (Low <= High)
    {
        int Mid = Low + (High - Low) / 2;
        if (x == Arr[Mid])
        {
            return Mid;
        }
        else if (x < Arr[Mid])
        {
            High = Mid - 1;
        }
        else if (x > Arr[Mid])
        {
            Low = Mid + 1;
        }
    }
    return -1;
}

int descendingBinarySearch(int Arr[], int Size, int x)
{
    int Low = 0, High = Size - 1;
    while (Low <= High)
    {
        int Mid = Low + (High - Low) / 2;
        if (x == Arr[Mid])
        {
            return Mid;
        }
        else if (x < Arr[Mid])
        {
            Low = Mid + 1;
        }
        else if (x > Arr[Mid])
        {
            High = Mid - 1;
        }
    }
    return -1;
}

int bitonicElement(int Arr[], int Low, int High)
{
    if (Low <= High)
    {
        int Mid = Low + (High - Low) / 2;
        if (Arr[Mid] < Arr[Mid - 1])
        {
            return bitonicElement(Arr, Low, Mid - 1);
        }
        else if (Arr[Mid] < Arr[Mid + 1])
        {
            return bitonicElement(Arr, Mid + 1, High);
        }
        else
        {
            return Mid;
        }
    }
    return -1;
}

int searchInBitonicArray(int Arr[], int n, int Search, int bitonicIndex)
{
    if (Search > Arr[bitonicIndex])
    {
        return -1;
    }

    if (Search == Arr[bitonicIndex])
    {
        return bitonicIndex;
    }

    else if (Search < Arr[bitonicIndex])
    {
        int Index1 = ascendingBinarySearch(Arr, n, Search);
        if (Index1 != -1)
        {
            return Index1;
        }

        return descendingBinarySearch(Arr, n, Search);
    }
    return -1;
}

int main(void)
{
    int Arr[] = {10, 20, 30, 40, 50, 30, 20};
    int Search = 50;
    int Size = sizeof(Arr) / sizeof(Arr[0]);

    int bitonicIndex = bitonicElement(Arr, 1, Size - 2);

    int searchIndex = searchInBitonicArray(Arr, Size, Search, bitonicIndex);
    cout << searchIndex;
    return 0;
}
