/*
Given two strings, check if they are anagrams of each other.

APPROACH 1:-
Sort both the strings
Return true if both strings are equal after sorting

Time Complexity : O(nlogn)
Space Complexity : O(1)

APPROACH 2:-
This assumes that the string contains only lowercase letters
Create a frequency array of size 26.
For every character found in s1, perform A[s1[i]-'a']++
For every character found in s2, perform A[s2[i]-'a']++

If the strings contain characters besides lowercase characters, use an unordered_map.

Time Complexity : O(n) + O(n) ~ O(n)
Space Complexity : O(1), if it contains only lowercase letters and O(n) otherwise
*/

#include <iostream>
#include <string>

using namespace std;

bool validAnagram(string s1, string s2)
{
    if (s1.length() != s2.length())
        return false;

    int freqArray[26] = {0};

    for (int i = 0; i < s1.length(); i++)
    {
        freqArray[s1[i] - 'a']++;
        freqArray[s2[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++)
    {
        if (freqArray[i])
            return false;
    }

    return true;
}

int main(void)
{
    string s1 = "naman", s2 = "amann";
    cout << validAnagram(s1, s2);
    return 0;
}
