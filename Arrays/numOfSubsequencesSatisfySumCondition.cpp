/*
Given an array of integers nums and an integer target.

Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum element on it is less or equal to target. Since the answer may be too large, return it modulo (10)^9 + 7.

APPROACH:
1. This question is very similar to the Two Sum problem.
2. We are looking for the smallest and largest element in a subsequence.
3. Thus, if we sort the array the min element will be the first element of the subsequence and the max element will be the last element of the subsequence.
4. Sort the array 
5. For each A[i], find out the maximum A[j] that A[i] + A[j] <= target.
6. We now have a subarray which satisfies the given condition.
7. The number of ways we can create a subsequence out of an array is 2^n. Here, n is the size of the array.
8. Let us fix the element at A[left]. Thus, we can choose subsequence in the range of A[left+1]...A[right].
9. The number of elements in range of left+1 and right will be (right-(left+1)+1) = (right-left)
10. Thus, increment count by 2^(right-left).
11. Return count once left>right.

Time Complexity : O(nLogn)
Space Complexity : O(N)
*/

#include <iostream>
#include <vector>

using namespace std;

int numOfSubsequences(vector<int> V, int k)
{
    const int MOD = 1e9 + 7;
    int n = V.size();

    vector<int> pows(n, 1);
    for (int i = 1; i < n; ++i)
        pows[i] = (2 * pows[i - 1]) % MOD;

    int l = 0, r = n - 1, count = 0;
    while (l <= r)
    {
        if (V[l] + V[r] > k)
            r--;
        else
        {
            count = (count + pows[r - l]) % MOD;
            l++;
        }
    }
    return count;
}

int main(void)
{
    vector<int> V = {3, 5, 6, 7};
    int Target = 9;
    cout << numOfSubsequences(V, Target);
    return 0;
}
