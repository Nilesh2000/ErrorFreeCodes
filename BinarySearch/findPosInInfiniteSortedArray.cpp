/*
Program to search for an element in a sorted array of infinite numbers.
Here, we implement the notion of the infinite array using an array whose size we are unaware of
Hint : Use Binary Search
Our aim first should be to we have to find the bounds on which we have to apply the binary search algorithm.
*/

#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> V, int Low, int High, int Key)
{
    int Mid = Low + (High - Low) / 2;
    if (Low <= High)
    {
        if (V[Mid] == Key)
            return Mid;

        else if (V[Mid] > Key)
            return binarySearch(V, Low, Mid - 1, Key);

        else if (V[Mid] < Key)
            return binarySearch(V, Mid + 1, High, Key);
    }
    return -1;
}

// We don't know size of arr[] and we can assume size to be infinite in this function.
// NOTE THAT THIS FUNCTION ASSUMES arr[] TO BE OF INFINITE SIZE THEREFORE, THERE IS NO INDEX OUT OF BOUND CHECKING
int findPos(vector<int> V, int Key)
{
    int Low = 0, High = 1, Val = V[0];
    while (Val < Key)
    {
        Low = High;
        High = 2 * High;
        Val = V[High];
    }
    return binarySearch(V, Low, High, Key);
}

int main(void)
{
    vector<int> V = {20, 30, 40, 60, 75, 90, 110, 120, 135};
    int Key = 75;

    cout << findPos(V, Key);

    return 0;
}
