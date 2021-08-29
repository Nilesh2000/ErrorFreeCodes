/*
Given a string, find the first unique character and its index in the string.

APPROACH:
Traverse the string and store the frequency of each character in an unordered_map.
Traverse the string again and return the first character whose frequency is 1.

Time Complexity : O(n) + O(n) ~ O(n)
Space Complexity : O(n)
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

void firstUniqueCharacter(string s)
{
    int n = s.length();
    unordered_map<char, int> M;
    for (int i = 0; i < n; i++)
        M[s[i]]++;

    for (int i = 0; i < n; i++)
    {
        if (M[s[i]] == 1)
        {
            cout << "Character : " << s[i] << " Index : " << i;
            break;
        }
    }
    cout << "All characters appear atleast twice.";
}

int main(void)
{
    string s = "leetcode";
    firstUniqueCharacter(s);
    return 0;
}
