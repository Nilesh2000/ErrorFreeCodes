/*
Given binary array, find count of maximum number of consecutive 1’s present in the array.

Time Complexity : O(n)
Space Complexity : O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

int maxConsecutiveOnes(vector<int> V)
{
    int n = V.size();
    int cnt = 0;
    int maxLen = 0;
    for (int num : V)
    {
        if (num)
        {
            cnt++;
            maxLen = max(maxLen, cnt);
        }
        else
        {
            cnt = 0;
        }
    }
    return maxLen;
}

int main(void)
{
    vector<int> V = {1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0};
    cout << maxConsecutiveOnes(V);
    return 0;
}
