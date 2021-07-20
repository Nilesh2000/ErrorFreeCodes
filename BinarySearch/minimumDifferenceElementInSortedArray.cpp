// Given a sorted array, find the element in the array which has minimum difference with the given number.

// Another approach than applying binary search here is that we can find the ceil and floor of the key and compare which one will return a smaller difference.

#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int minimumDifferenceElement(int Arr[], int n, int Key)
{
    if (Arr[0] > Key)
    {
        return Arr[0] - Key;
    }

    if (Arr[n - 1] < Key)
    {
        return Key - Arr[n - 1];
    }

    int Low = 0, High = n - 1;

    while (Low <= High)
    {
        int Mid = Low + (High - Low) / 2;
        if (Arr[Mid] == Key)
        {
            return 0;
        }
        else if (Arr[Mid] > Key)
        {
            High = Mid - 1;
        }
        else if (Arr[Mid] < Key)
        {
            Low = Mid + 1;
        }
    }

    return min(Key - Arr[High], Arr[Low] - Key);
}

int main(void)
{
    int Arr[] = {4, 5, 6, 8, 9};
    int Key = 5;
    int Size = sizeof(Arr) / sizeof(Arr[0]);
    int minDiff = minimumDifferenceElement(Arr, Size, Key);
    cout << minDiff;
    return 0;
}
