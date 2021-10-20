/*
Given an array consisting of N+1 elements in the range of [1,N], one element of the array occurs twice.
Find that duplicate element.

APPROACH 1:
1. XOR all the elements of the array
2. XOR the result with 1 to n-1
3. That will be the duplicate number
4. This method does not mutate the array.

Time Complexity : O(2n) ~ O(n)
Space Complexity : O(1)

APPROACH 2:
1. Use cyclic sort to place all the integers in the range of [1,N] at their correct positions.
2. If an integer is already present at index it should be placed at, its a duplicate.
3. Return the duplicate number

Time Complexity : O(n)
Space Complexity : O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

int findDuplicate(vector<int> V)
{
    int duplicateNum = 0;
    int n = V.size();

    for (auto num : V)
        duplicateNum ^= num;

    for (int i = 1; i < n; i++)
        duplicateNum ^= i;

    return duplicateNum;
}

int findDuplicateCyclicSort(vector<int> V)
{
    int i = 0, n = V.size();
    // Iterate from start to end of array
    while (i < n)
    {
        // In a sorted array, the index of the element V[i] should be V[i]-1
        // If it is not present, there are two cases. Either the number is unique or it is a duplicate
        if (V[i] - 1 != i)
        {
            // The index of the element V[i] should be V[i]-1
            int correct = V[i] - 1;

            // If the element is not present at the computed index, it's a unique number
            if (V[i] != V[correct])
                swap(V[i], V[correct]);
            // If the number is present at that index, then its a duplicate.
            else
                return V[i];
        }
        // If the number is present at the correct index, move forward in the array
        else
            i++;
    }
    return -1;
}

int main(void)
{
    vector<int> V = {2, 1, 2, 4, 3};
    cout << findDuplicate(V) << '\n';
    cout << findDuplicateCyclicSort(V);
    return 0;
}
