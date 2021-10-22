/*
Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

APPROACH 1:
1. Iterate over the array elements and create a frequency array/hash map.
2. Iterate over the hash map and store all those elements in the result vector which have a frequency of 2.
3. Return the result vector.

Time Complexity : O(N)
Space Complexity : O(N)

APPROACH 2:
1. Use cyclic sort to place all the integers in the range of [1,N] at their correct positions.
2. All integers which are not at index V[i] - 1 are duplicates. Push them into duplicates array.
3. Return the duplicates array.

Time Complexity : O(N)
Space Complexity : O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> allDuplicates(vector<int> V)
{
    int i = 0;
    int n = V.size();

    vector<int> duplicates;

    while (i < n)
    {
        int correct = V[i] - 1;
        if (V[i] != V[correct])
            swap(V[i], V[correct]);
        else
            i++;
    }

    for (int i = 0; i < n; i++)
    {
        if (i != V[i] - 1)
            duplicates.push_back(V[i]);
    }

    return duplicates;
}

int main(void)
{
    vector<int> V = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> duplicates = allDuplicates(V);

    for (auto num : duplicates)
        cout << num << " ";

    return 0;
}
