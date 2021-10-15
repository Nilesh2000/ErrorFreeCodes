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
#include <vector>

using namespace std;

int secondLargestElement(vector<int> V)
{
    if (V.size() < 2)
        return -1;

    int largest, secondLargest;
    largest = secondLargest = V[0];

    for (auto num : V)
    {
        if (num > largest)
        {
            secondLargest = largest;
            largest = num;
        }
    }
    return secondLargest;
}

int main(void)
{
    vector<int> V = {1, 3, 4, 5, 2};
    cout << secondLargestElement(V);
    return 0;
}
