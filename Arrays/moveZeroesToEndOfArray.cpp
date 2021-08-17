/*
Given an array of random numbers, Push all the zero’s of a given array to the end of the array.

Approach:
Maintain a count of all non-zero integers.
While traversing the array, if you come across a non-zero integer, set V[c++]=V[i]
After the array traversal, all non-zero elements are at the front and count is at the first index of 0.
Now, run a loop which makes all array elements 0 from count index till end of array

Time Complexity : O(n)
Space Complexity : O(1)

FOLLOW UP:
Minimize the number of operations done, that is do it with one loop.
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> moveZeroesToEnd(vector<int> V)
{
    int c = 0;
    int n = V.size();

    for (int i = 0; i < n; i++)
    {
        if (V[i] != 0)
            V[c++] = V[i];
    }

    while (c < n)
        V[c++] = 0;

    return V;
}

vector<int> moveZeroesToEndEfficient(vector<int> V)
{
    int m = 0;
    int n = V.size();

    for (int i = 0; i < n; i++)
    {
        if (V[i] == 0)
            m++;
        else if (m != 0)
        {
            V[i - m] = V[i];
            V[i] = 0;
        }
    }

    return V;
}

int main(void)
{
    vector<int> V = {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9};
    V = moveZeroesToEnd(V);
    for (int num : V)
        cout << num << " ";
    cout << "\n";
    V = moveZeroesToEndEfficient(V);
    for (int num : V)
        cout << num << " ";
    return 0;
}
