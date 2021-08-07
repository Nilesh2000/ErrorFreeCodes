// Given a sorted array and an integer n, find the index of insertion of the integer n
// Time Complexity : O(log n)
// Space Complexity : O(1)
#include <iostream>

using namespace std;

int indexOfInsertion(int Arr[], int n, int Target)
{
    int Low = 0, High = n - 1;
    while (Low <= High)
    {
        int Mid = Low + (High - Low) / 2;
        if (Arr[Mid] < Target)
            Low = Mid + 1;
        else
            High = Mid - 1;
    }
    return Low;
}

int main(void)
{
    int Arr[] = {1, 2, 3, 5, 6};
    int n = sizeof(Arr) / sizeof(Arr[0]);
    int Element = 4;
    cout << indexOfInsertion(Arr, n, Element);
    return 0;
}
