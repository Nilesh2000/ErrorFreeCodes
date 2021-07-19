// Given an infinite sorted array consisting 0s and 1s. The problem is to find the index of first ‘1’ in that array.
// As the array is infinite, therefore it is guaranteed that number ‘1’ will be present in the array.

// The problem is closely related to the problem of finding position of an element in a sorted array of infinite numbers.
// As the array is infinite, therefore we do not know the upper and lower bounds between which we have to find the occurrence of first ‘1’.

#include <iostream>
using namespace std;

int binarySearch(int Arr[], int Low, int High)
{
    int Mid;
    while (Low <= High)
    {
        Mid = Low + (High - Low) / 2;

        if (Arr[Mid] == 1 && (Arr[Mid - 1] == 0 || Mid == 0))
        {
            break;
        }
        else if (Arr[Mid] == 0)
        {
            Low = Mid + 1;
        }
        else if (Arr[Mid] == 1)
        {
            High = Mid - 1;
        }
    }
    return Mid;
}

int findPos(int Arr[])
{
    int Low = 0;
    int High = 1;
    while (Arr[High] == 0)
    {
        Low = High;
        High = 2 * High;
    }
    return binarySearch(Arr, Low, High);
}

int main(void)
{
    int Arr[] = {0,
                 0,
                 0,
                 0,
                 0,
                 0,
                 0,
                 1,
                 1,
                 1,
                 1,
                 1};
    int posOfFirstOne = findPos(Arr);
    cout << posOfFirstOne;
    return 0;
}
