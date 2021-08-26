/*
Given an array of distinct integers and a target integer, return a list of all possible unique combinations where the chosen numbers sum up to target. The same number can be chosen from the array multiple times.

This is a backtracking problem.
Backtracking can be defined as a general algorithmic technique that considers searching every possible combination in order to solve a computational problem.

Sort the candidates array.
Remove duplicates since we are allowed to reuse the same element.
We start with index 0 of the array.
We can either pick or not pick the element at index 0 in the array.
We do this recursively for every element in the array until either we reach the end of the array or if the sum of the elements becomes equal to target.
Incase we do reach the end of the array, we backtrack by removing the last element in the array.
Incase the sum of the array elemnts becomes equal to target, we append the array to the resultant vector and then backtrack to look for more combinations.

Assuming that for each recursive step we go over all existing candidates, so base N.
And go as deep as target in our recursive calls (if candidates are close to 1), so power of target.

Time Complexity : O(N^target) [N is the length of the candidates array]
Space Complexity : O(target)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void findCombinations(int index, int target, vector<int> candidates, vector<int> ds, vector<vector<int>> &combinations)
{
    // If you have reached the end of the array, return
    if (index == candidates.size())
        return;

    // If the sub-problem results in a sum of 0, append the vector to the combinations vector
    if (target == 0)
    {
        combinations.push_back(ds);
        return;
    }

    // We choose the element present at index 'index' in the candidates array only if that element is smaller than the target to be computed
    if (candidates[index] <= target)
    {
        ds.push_back(candidates[index]);
        findCombinations(index, target - candidates[index], candidates, ds, combinations);
        ds.pop_back();
    }

    findCombinations(index + 1, target, candidates, ds, combinations);
}

vector<vector<int>> combinationSum(vector<int> V, int x)
{
    int Index = 0;
    vector<int> A;
    vector<vector<int>> Res;

    // Sort the candidates array
    sort(V.begin(), V.end());
    // Remove duplicates
    V.erase(unique(V.begin(), V.end()), V.end());

    findCombinations(Index, x, V, A, Res);
    return Res;
}

int main(void)
{
    vector<int> V = {2, 3, 5};
    int target = 8;
    vector<vector<int>> C = combinationSum(V, target);

    for (int i = 0; i < C.size(); i++)
    {
        if (C[i].size() > 0)
        {
            cout << "[ ";
            for (int j = 0; j < C[i].size(); j++)
            {
                cout << C[i][j] << " ";
            }
            cout << "]" << '\n';
        }
    }

    return 0;
}
