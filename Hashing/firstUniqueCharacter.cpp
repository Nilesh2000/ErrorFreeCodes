/*
Given a string, find the first unique character and its index in the string.

APPROACH:
1. Traverse the string and store the frequency of each character in an unordered_map.
2. Traverse the string again and return the first character whose frequency is 1.

Time Complexity : O(n) + O(n) ~ O(n)
Space Complexity : O(n)
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

pair<char, int> firstUniqueCharacter(string s)
{
    int n = s.length();
    unordered_map<char, int> M;

    for (int i = 0; i < n; i++)
        M[s[i]]++;

    for (int i = 0; i < n; i++)
    {
        if (M[s[i]] == 1)
            return {s[i], i};
    }
    return {'\0', -1};
}

int main(void)
{
    string s = "leetcode";
    // string s = "aaa";

    pair<char, int> P = firstUniqueCharacter(s);
    cout << P.first << " " << P.second;

    return 0;
}
