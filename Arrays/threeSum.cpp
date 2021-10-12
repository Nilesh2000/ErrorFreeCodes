/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

APPROACH 1:-
1. A naive solution would be to generate all the distinct triplets and see which ones sum up to k.
2. Push the set of triplets which sum up to k into a double dimensional vector.
3. Return the result vector.

Time Complexity : O(N^3)
Space Complexity : O(1)

APPROACH 2:-
1. Try and convert the problem to a two-sum problem.
2. Fix one element and apply the two-sum problem over the remaining elements of the problem.
3. The size of the array becomes n-1 and the sum becomes sum - a[i].

Time Complexity : O(N^2)
Space Complexity : O(N)

APPROACH 3:-
1. Sort the input array.
2. Apply approach 1 here except that the array is sorted here.
3. So, we can use the 2-pointer approach.
4. Stop

Time Complexity : O(N*Log(N) + O(N^2)
Space Complexity : O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int> V)
{
    vector<vector<int>> Res;
    int n = V.size();
    if (n < 3)
        return Res;

    sort(V.begin(), V.end());
    int Target = 0;

    for (int i = 0; i < n - 2; i++)
    {
        if (i > 0 && V[i] == V[i - 1]) // Continue because we do not want duplicate triplets
            continue;

        if (V[i] > Target) // Since array is sorted there will be integers in the range of [i+1...N] which sum up to k if V[i] > k
            break;

        int Left = i + 1, Right = n - 1;
        while (Left < Right)
        {
            int Sum = V[i] + V[Left] + V[Right];

            if (Sum == Target)
            {
                Res.push_back({V[i], V[Left], V[Right]});

                // Ignore duplicates
                while (Left < Right && V[Left] == V[Left + 1])
                    Left++;
                while (Right > Left && V[Right] == V[Right - 1])
                    Right--;

                // Move on to next iteration
                Left++;
                Right--;
            }
            else if (Sum > Target)
                Right--;
            else
                Left++;
        }
    }
    return Res;
}

int main(void)
{
    vector<int> V = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> R = threeSum(V);
    for (int i = 0; i < R.size(); i++)
    {
        cout << "[ ";
        for (int j = 0; j < 3; j++)
            cout << R[i][j] << " ";
        cout << "]\n";
    }
    return 0;
}
