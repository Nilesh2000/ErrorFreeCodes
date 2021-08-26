/*
Given an array of integers and a target integer, return a list of all possible unique combinations where the chosen numbers sum up to target. A number can be chosen only once for a combination from the array.
All the combinations should be in sorted order.
The combinations must be ordered lexicographically.

APPROACH:-
Similar to combinationSumI problem. We do not remove duplicates in this program.
However, here we do not have the option to pick the same element. So we have to index+1 in every recursive call.
But, this might result in a duplicate combination, so instead of return a 2-D vector we can return a set of vectors which will eliminate any duplicate combinations.
This will result in an increase in time complexity by a factor of O(Log(Size of Vector))

Subsequence Approach:
When there are N elements, there will be 2^N subsequences.
https://www.youtube.com/watch?v=G1fRTGRxXU8&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=54&ab_channel=takeUforward
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void findCombinations(int ind, int target, vector<int> candidates, vector<int> &ds, vector<vector<int>> &combinations)
{
    // If the sub-problem results in a sum of 0, append the vector to the combinations vector
    if (target == 0)
    {
        combinations.push_back(ds);
        return;
    }

    // Loop through each of the subsequences
    for (int i = ind; i < candidates.size(); i++)
    {
        // If that subsequence has already been picked, ignore that array element
        // Ignore duplicate combinations
        if (i > ind && candidates[i] == candidates[i - 1])
            continue;

        // Since the array is sorted, if an array element becomes greater than target and all elements on the right of candidates[i] will be greater than target, we break out of the loop
        if (candidates[i] > target)
            break;

        ds.push_back(candidates[i]);

        // We do not perform index + 1 but rather i+1 becuase we push candidates[i] into the array and not candidates[index].
        findCombinations(i + 1, target - candidates[i], candidates, ds, combinations);
        ds.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> V, int x)
{
    int index = 0;
    vector<int> ds;
    vector<vector<int>> combinations;

    // Sort the candidates array so that we can have all combinations of numbers in sorted order
    sort(V.begin(), V.end());

    findCombinations(index, x, V, ds, combinations);
    return combinations;
}

int main(void)
{
    vector<int> V = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> Ans = combinationSum(V, target);

    for (int i = 0; i < Ans.size(); i++)
    {
        if (Ans[i].size() > 0)
        {
            cout << "[ ";
            for (int j = 0; j < Ans[i].size(); j++)
            {
                cout << Ans[i][j] << " ";
            }
            cout << "]" << '\n';
        }
    }

    return 0;
}
