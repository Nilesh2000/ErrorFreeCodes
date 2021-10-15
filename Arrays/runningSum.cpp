/*
Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).
Time Complexity : O(n)
Space Complexity : O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    vector<int> V = {1, 2, 3, 4, 5};
    int n = V.size();

    for (int i = 1; i < n; i++)
        V[i] += V[i - 1];

    for (auto num : V)
        cout << num << " ";

    return 0;
}
