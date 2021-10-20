/*
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.

OBSERVATION:
We should not insert elements into a set since we do not have to return a vector, but an integer representing the new vector size.
That is, we should move all the duplicates towards the end of the array.
And then return the new size of the array.

APPROACH:
1. Maintain two pointers. Let i=0 and j=1.
2. Iterate till the end of the vector. If V[i]!=V[j], move i forward and set V[i]=V[j].
3. Return i+1 at after the for loop is elapsed.

Time Complexity : O(N)
Space Complexity : O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int> &V)
{
    int n = V.size();
    if (n == 0 || n == 1) //If the array has no elements or 1 element, it has no duplicates.
        return n;

    int i = 0;
    for (int j = 1; j < n; j++)
    {
        if (V[i] != V[j])
        {
            i++;
            V[i] = V[j];
        }
    }
    return i + 1;
}

int main(void)
{
    vector<int> V = {0, 0, 1, 1, 2, 3, 3, 4, 4, 4, 5};
    int n = removeDuplicates(V);
    for (int i = 0; i < n; i++)
        cout << V[i] << " ";
    return 0;
}
