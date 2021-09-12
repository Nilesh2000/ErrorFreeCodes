/*
An sorted array of integers was rotated an unknown number of times.
Given such an array, find the index of the element in the array in faster than linear time. 
If the element doesn't exist in the array, return -1

For example, given the array [13, 18, 25, 2, 8, 10] and the element 8, return 4 (the index of 8 in the array).
You can assume all the integers in the array are unique.

APPROACH:-
Find the pivot index in the given array, i.e the index of the largest element in the given rotated sorted array.
If the element to be searched is equal to the element at the pivot index then print the index of the pivot.
If the element to be searched is greater than the element at the pivot index then the element does not exist in the array.
If the element to be searched is less than the element at a pivot index then search for the element in both halves of the array using binary search.

Time Complexity : O(log n)
Space Complexity : O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

// Method to return the index of the largest element
int pivotIndex(vector<int> V)
{
    int n = V.size();
    int Low = 0, High = n - 1;

    while (Low <= High)
    {
        int Mid = Low + (High - Low) / 2;

        /*
        There can only be 1 index in the array where V[Mid]<V[Mid-1].
        That element at that index will be the smallest element in the array.
        Then V[Mid-1] will be the largest element in the array
        */
        if (Mid > Low && V[Mid] < V[Mid - 1])
            return Mid - 1;

        /*
        There can only be 1 index in the array where V[Mid] > V[Mid+1].
        That element at that index will be the largest element in the array.
        */
        if (Mid < High && V[Mid] > V[Mid + 1])
            return Mid;

        // If this is true, it indicates that the array is rotated and we have to search towards the left
        if (V[Mid] <= V[Low])
            High = Mid - 1;

        else
            Low = Mid + 1;
    }
    // If array is not rotated itself, then V[n-1] will be the largest element
    return n - 1;
}

int binarySearch(vector<int> V, int Low, int High, int x)
{
    if (Low <= High)
    {
        int Mid = Low + (High - Low) / 2;

        if (x == V[Mid])
            return Mid;

        else if (x > V[Mid])
            return binarySearch(V, Mid + 1, High, x);

        else if (x < V[Mid])
            return binarySearch(V, Low, Mid - 1, x);
    }
    return -1;
}

int circularArraySearch(vector<int> V, int x)
{
    int n = V.size();

    int pivotInd = pivotIndex(V);

    if (x == V[pivotInd])
        return pivotInd;

    else if (x > V[pivotInd])
        return -1;

    else
    {
        int Pos = binarySearch(V, 0, pivotInd - 1, x);
        if (Pos != -1)
            return Pos;

        Pos = binarySearch(V, pivotInd + 1, n - 1, x);
        if (Pos != -1)
            return Pos;
    }
    return -1;
}

int main(void)
{
    vector<int> V = {31, 38, 5, 8, 10, 12, 15, 22, 23, 28};
    int x = 29;

    cout << circularArraySearch(V, x);

    return 0;
}
