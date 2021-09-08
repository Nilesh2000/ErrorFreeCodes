/*
Given an array of intervals where intervals{i} = {starti, endi}, merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

QUESTION:-
Will the intervals be provided in sorted order?
If not, sort the intervals by increasing order of start time. If two start times are equal, sort them in increasing order of end time.

Time Complexity : O(N Log N) + O(N)
Space Complexity : O(N)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> V)
{
    int n = V.size();

    // Base Case
    if (n <= 1)
        return V;

    sort(V.begin(), V.end());

    vector<int> tempInterval = V[0];
    vector<vector<int>> M;

    for (auto interval : V)
    {
        if (interval[0] <= tempInterval[1])
            tempInterval[1] = max(tempInterval[1], interval[1]);
        else
        {
            M.push_back(tempInterval);
            tempInterval = interval;
        }
    }
    M.push_back(tempInterval);
    return M;
}

int main(void)
{
    vector<vector<int>> V = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> M = mergeIntervals(V);

    cout << "[ ";
    for (auto interval : M)
        cout << "[" << interval[0] << ", " << interval[1] << "], ";
    cout << "]";

    return 0;
}
