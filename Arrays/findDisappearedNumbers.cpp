/*
Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.

APPROACH:
Perform cyclic sort and then return i+1 for all [0...n-1] where i!=V[i]-1

Time Complexity : O(N)
Space Complexity : O(1)
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> findDisappearedNumbers(vector<int> V)
{
    int i = 0;
    int n = V.size();
    while (i < n)
    {
        // Compute the index for V[i]
        int correct = V[i] - 1;

        // If the computed index for V[i] does not match its actual index, swap it
        if (V[i] != V[correct])
            swap(V[i], V[V[i] - 1]);
        else
            i++;
    }

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (i != V[i] - 1)
            ans.push_back(i + 1);
    }
    return ans;
}

int main(void)
{
    vector<int> V = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> ans = findDisappearedNumbers(V);

    for (auto num : ans)
        cout << num << " ";

    return 0;
}
