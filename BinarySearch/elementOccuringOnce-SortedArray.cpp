// Given a sorted array in which all elements occur twice (one after one) except one element which occurs once. Find that element in O(log n) time complexity
// Time Complexity : O(log n)
// Space Complexity : O(1)
// We can XOR all the elements of the array to get the element occurring only once, but that would take O(1) time and it would be more suitable for an unsorted array

/*

Logic :
Let the element we require be x.
We can also say that the index of x must be even only.

For all elements before x,
1. The First Occurrence of the element will be at indices such as [0,2,..] which are even indices and the second occurrence will be at indices [1,3,...] which are odd indices.

For all elements after x,
1. The First Occurrence of the element will be at indices such as [7,9,..] which are odd indices and the second occurrence will be at indices [8,10,...] which are even indices.

1. Take Low and High Pointer. Low Points to 0, High Points to end of array
2. Find Mid. 
If Mid is even, its duplicate should be in Mid+1 index
If Mid is odd, its duplicate should be in Mid-1 index
If any of these two conditions is satisfied, 'x' will be in [Mid+1...High] range.
If the condition is not satisfied, 'x' will be in the range of [Low..Mid]
Return Arr[Low]
*/

#include <iostream>

using namespace std;

int elementOccurringOnce(int Arr[], int n)
{
    int Low = 0, High = n - 1;
    while (Low < High)
    {
        int Mid = Low + (High - Low) / 2;
        if ((Mid % 2 == 0 && Arr[Mid] == Arr[Mid + 1]) || (Mid % 2 == 1 && Arr[Mid] == Arr[Mid - 1]))
        {
            Low = Mid + 1;
        }
        else
        {
            High = Mid;
        }
    }
    return Arr[Low];
}

int main(void)
{
    int Arr[] = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    int n = sizeof(Arr) / sizeof(Arr[0]);
    cout << elementOccurringOnce(Arr, n);
    return 0;
}
