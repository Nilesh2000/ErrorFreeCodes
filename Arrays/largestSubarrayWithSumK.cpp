/*
Given an array, find the length of the largest subarray whose sum is equal to 0. Also, find the number of subarrays whose sum equals k.

APPROACH:-
Brute-Force
Run two nested loops.
First loop (i) runs from 0 to n-1.
Second loop (j) from runs from i to n-1. Add curr_sum to arr[j]
If arr[j] equals k, calculate max(maxLen, j-i+1) and increment count of subarrays whose sum equals k

Time Complexity : O(n^2)
Space Complexity : O(1)

HashMap Approach:-
The logic here is that if the sum of a subarray from [0...i] is S and the sum of a subarray from [0...j] is S - k, then the sum of the subarray [j+1...i] must be k.

Time Complexity : O(n log n) (Traverse The Array And Insert Each Element Into the Hashmap)
Space Complexity : O(n) (Hash Map takes up O(n) space)
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int largestSubarrayWithKSum(vector<int> V, int k)
{
    unordered_map<int, int> M;
    int maxLen = 0;
    int Sum = 0;
    int n = V.size();

    // Traverse the vector linearly
    for (int i = 0; i < n; i++)
    {
        // Increment sum by V[i]
        Sum += V[i];

        // If Sum becomes equal to k, set length of subarray to be i+1
        if (Sum == k)
            maxLen = i + 1;

        else
        {
            if (M.find(Sum - k) != M.end())
                maxLen = max(maxLen, i - M[Sum]);
            else
                M[Sum] = i;
        }
    }
    return maxLen;
}

int countOfSubarrayWithSumEqualToK(vector<int> V, int k)
{
    int cumSum = 0;
    int Count = 0;
    int n = V.size();
    unordered_map<int, int> M;

    for (int i = 0; i < n; i++)
    {
        // Increment cumSum at each step
        cumSum += V[i];

        // If cumSum equals k, then increment Count
        if (cumSum == k)
            Count++;

        if (M.find(cumSum - k) != M.end())
            Count += M[cumSum - k];

        M[cumSum]++;
    }
    return Count;
}

int main(void)
{
    vector<int> V = {10, 2, -2, -20, 10};
    int k = -10;
    cout << "Length of the largest subarray with sum equal to k : " << largestSubarrayWithKSum(V, k);
    cout << "\nNumber of subarrays with sum equal to k : " << countOfSubarrayWithSumEqualToK(V, k);
    return 0;
}
