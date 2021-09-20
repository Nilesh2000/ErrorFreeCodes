/*
You are given 2 vectors V1 and V2.
Each element is a pair of integers where the first integer represents the unique ID and the second integer represents a value.
Your task is to find an element from V1 and an element form V2 such that the sum of their values is less or equal to target and as close to target as possible.
Return a list of IDs of selected elements. 
If no pair is possible, return an empty list.

APPROACH:
Sort both the array in asceding order of values.
Use two-pointer algorithm to find the largest sum which is smaller than target.

Time Complexity : O(MLogM) + O(NLogN) + O(MN)
Space Complexity : O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

bool compare(const vector<int> &V1, const vector<int> &V2)
{
    return V1[1] < V2[1];
}

vector<vector<int>> optimalSum(vector<vector<int>> V1, vector<vector<int>> V2, int k)
{
    // Sort both arrays in ascending order of values
    sort(V1.begin(), V1.end(), compare);
    sort(V2.begin(), V2.end(), compare);

    vector<vector<int>> V = {};

    // Initialize the maximum sum
    int maxSum = INT_MIN;

    int m = V1.size();
    int n = V2.size();

    // Start from beginning of V1 and end of V2
    int left = 0, right = n - 1;

    while (left < m && right >= 0)
    {
        // Compute the sum of the values
        int valueSum = V1[left][1] + V2[right][1];

        // If sum is greater than k, decrement right by 1
        if (valueSum > k)
            right--;

        // If sum is lesser than k
        else
        {
            // If the maximum sum computed until now is lesser than or equal to the current computed sum
            if (maxSum <= valueSum)
            {
                // Since there exists a greater sum, clear the result vector
                if (maxSum < valueSum)
                {
                    maxSum = valueSum;
                    V.clear();
                }

                // Insert the values on the left and right indices
                V.push_back({V1[left][0], V2[right][0]});
                int index = right - 1;

                // Iterate till the beginning of V2 so as to check for pairs having the same value
                while (index >= 0 && V2[index][1] == V2[index + 1][1])
                    V.push_back({V1[left][0], V2[index--][0]});
            }
            left++;
        }
    }

    return V;
}

int main(void)
{
    vector<vector<int>> V1 = {{1, 3}, {2, 5}, {3, 7}, {4, 10}};
    vector<vector<int>> V2 = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    int k = 10;

    vector<vector<int>> V = optimalSum(V1, V2, k);

    for (int i = 0; i < V.size(); i++)
        cout << "[" << V[i][0] << ", " << V[i][1] << "]\n";

    return 0;
}
