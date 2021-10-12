/*
Given a string s, find the length of the longest substring without repeating characters.

ALGORITHM 1:
1. Generate all substrings.
2. Iterate over each substring and insert each character into a hashset.
3. Keep track of the length of the longest substring without repeating characters.
4. Return the maximum length of the substring without repeating characters.

ALGORITHM 2:
1. Use two pointers. Both pointers initially point to the first character of the string.
2. Create an empty set.
3. Iterate over the string till s[right] is not present in the set. Increment right by 1 at after each iteration.
4. Update the maximum length at every iteration. Calculate length using formula right-left+1.
5. If s[right] exists in the set, delete s[left++] from the set until s[right] still exists in the set.
6. Once s[right] does not exist in the set, insert it into the set.

Time Complexity : O(2*N) (Each character will be visited by the left and right pointer once in the worst case)
Space Complexity : O(N)

ALGORITHM 3:
The problem with ALGORITHM 2 comes when we see two same consecutive characters.
In such cases, the left pointer has to iterate over each character and check if s[left] is the same as s[right], left < right.

1. Instead of using a unordered_set, use a map.
2. Store the character along with its index.
3. If s[right] already exists in the map, retrieve the first occurrence of s[right] from the map and move left forward by 1 position.
4. Also, update the position of s[right] in the map.
5. Calculate the maximum length at each iteration.
6. Return the maximum length.

Time Complexity : O(N)
Space Complexity : O(N)
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int longestSubstringWithoutRepeatingCharacters(string s)
{
    int left = 0, right = 0, n = s.length(), maxLen = 0;
    unordered_map<char, int> M;

    while (right < n)
    {
        if (M.find(s[right]) != M.end())
            left = max(left, M[s[right]] + 1);

        M[s[right]] = right;
        maxLen = max(maxLen, right - left + 1);
        right++;
    }
    return maxLen;
}

int main(void)
{
    string s = "abba";
    cout << longestSubstringWithoutRepeatingCharacters(s);
    return 0;
}
