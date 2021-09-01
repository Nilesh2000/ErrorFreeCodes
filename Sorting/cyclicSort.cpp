/*
Given an unsorted array of size N containing elements in the range of [1,n], sort the array in a single pass.

APPROACH:
In a sorted array of size N containing elements in the range of [1,N], the position of an element V[i] should be i+1 for i in range of [0,n-1]
Compute the correct index of the element at i.
If the computed index does not match the actual index, swap the elements at the computed index and the actual index

Time Complexity : O(N)
Space Complexity : O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> cyclicSort(vector<int> V)
{
    int i = 0, n = V.size();

    while (i < n)
    {
        // Compute the index for V[i]
        int correct = V[i] - 1;

        // If the computed index for V[i] does not match its actual index, swap it
        if (V[i] != V[correct])
            swap(V[i], V[correct]);
        else
            i++;
    }
    return V;
}

int main(void)
{
    vector<int> V = {3, 5, 1, 2, 4};
    V = cyclicSort(V);

    for (auto num : V)
        cout << num << " ";

    return 0;
}
