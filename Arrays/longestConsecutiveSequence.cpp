/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

APPROACH:
Sort the array.
If nums[i] != nums[i-1]
    If nums[i] == nums[i-1]+1
        Increment the current streak
Return the max of the currentStreak and longestStreak
Time Complexity : O(nlogn)
Space Complexity : O(1)

Insert all numbers into an unordered_set.
Iterate the array again and for each element, check if V[i]-1 exists in the set.
If it does not, iterate till V[i]+1 exists in the set and increment the longestStreak

Time Complexity : O(n)
Space Complexity : O(n)
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int longestConsecutiveSequence(vector<int> V)
{
    unordered_set<int> S;
    int n = V.size();
    int longestStreak = 0;

    for (int i = 0; i < n; i++)
        S.insert(V[i]);

    for (int i = 0; i < n; i++)
    {
        if (S.find(V[i] - 1) == S.end())
        {
            int currentStreak = 1;
            int currNum = V[i];

            while (S.find(currNum + 1) != S.end())
            {
                currentStreak++;
                currNum++;
            }

            longestStreak = max(longestStreak, currentStreak);
        }
    }
    return longestStreak;
}

int main(void)
{
    vector<int> V = {1, 2, 3, 100, 300, 200, 4};
    cout << longestConsecutiveSequence(V);
    return 0;
}
