/*
Given an unsorted array of size n, find the second largest element in the array.
If the size of the array is lesser than 2, return -1.

Approach 1:-
Sort the array in descending order and return Arr[1]

Time Complexity : O(n logn)
Space Complexity : O(1)

Approach 2:-
Initialize largest and secondLargest to Arr[0]
Traverse from 1 to n and check if Arr[i] is greater than largest
If it is, set secondLargest to largest and set largest to Arr[i]

Time Complexity : O(n)
Space Complexity : O(1)
*/

#include <iostream>

using namespace std;

int secondLargestElement(int Arr[], int n)
{
    if (n < 2)
        return -1;
    int largest, secondLargest;
    largest = secondLargest = Arr[0];
    for (int i = 0; i < n; i++)
    {
        if (Arr[i] > largest)
        {
            secondLargest = largest;
            largest = Arr[i];
        }
    }
    return secondLargest;
}

int main(void)
{
    int Arr[] = {1, 3, 4, 5, 2};
    int n = sizeof(Arr) / sizeof(Arr[0]);
    cout << "The Second Largest Element In The Array Is : " << secondLargestElement(Arr, n);
    return 0;
}
