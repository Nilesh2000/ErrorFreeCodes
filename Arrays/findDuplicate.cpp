// Given an array consisting of N+1 elements in the range of [1,N], one element of the array occurs twice.
// Find that duplicate element.

/*
XOR all the elemnts of the array
XOR the result with 1 to n-1
That will be the missing number

Time Complexity : O(2n) ~ O(n)
Space Complexity : O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

int findDuplicate(vector<int> V)
{
    int Res = V[0];
    int n = V.size();

    for (int i = 1; i < n; i++)
        Res ^= V[i];

    for (int i = 1; i < n; i++)
        Res ^= i;

    return Res;
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
