/*
Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.
A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:
--> 0 <= i < j < nums.length
--> |nums[i] - nums[j]| == k

APPROACH 1:
1. count = 0
2. Iterate i from 0 to n-1
    2.1 Iterate j from i+1 to n-1
        2.1.1 if abs(V[i]-V[j])==0:
            2.1.1.1 count++
3. Return count

Time Complexity : O(N^2)
Space Complexity : O(1)

APPROACH 2:
1. count=0
2. Store the frequency of each array element in a hash map.
3. Iterate over each element in the map.
    3.1 If k==0
        3.1.1 If frequency of the element is >=2:
            3.1.1.1 count++
        3.1.2 Check if x + k exists in the hash map
            3.1.2.1 count++
4. Return count

Time Complexity : O(N)
Space Complexity : O(N)
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int kDiffPairs(vector<int> V, int k)
{
    if (k < 0)
        return 0;

    unordered_map<int, int> M;
    for (auto num : V)
        M[num]++;

    int cnt = 0;
    for (auto x : M)
    {
        if (k == 0)
        {
            if (x.second >= 2)
                cnt++;
        }
        else
        {
            /*
            Here, we have to find the absolute values of V[i]-V[j] where i<j
            Since V is sorted and it is required that i < j, and thus V[i] < V[j]
            So for an array element x, we can get a absolute difference of k, if there exists another array element x+k.
            */
            if (M.find(x.first + k) != M.end())
                cnt++;
        }
    }
    return cnt;
}

int main(void)
{
    vector<int> V = {3, 1, 4, 1, 5, 1};
    int k = 2;

    // vector<int> V = {1, 3, 1, 5, 4};
    // int k = 0;

    cout << kDiffPairs(V, k);
    return 0;
}
