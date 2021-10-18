/*
Given an array of strings, return groups of all strings that are anagrams.
Represent a group by a list of integers representing the index in the original list.

APPROACH 1:
1. Sort the strings individually using counting sort. Do not sort the array.
2. For strings which are anagrams, after sorting they will become equal.
3. Then, use a hash map to group the anagrams.
4. Create a map of type map<string, vector<int>>. 
5. string will store all the unique strings. vector<int> will store all the indices of the unique string.
6. Then, we will iterate over the map and if the size of the vector is >=2 for a particular unique string, we print out the vector.

Time Complexity : O(N*K) [N is the number of strings, K is the length of the longest string]
Space Complexity : O(N) [Map]

APPROACH 2:
1. Two strings are anagrams if the frequency of each character in the string is the same.
2. Iterate over each string and calculate its frequency array. This will take O(26) space because the given string has only lowercase letters.
3. Create a map of type map<vector<int>,vector<int>>
4. The first vector<int> represents the frequency array.
5. The second vector<int> will store all the indices of the string which have the same frequency array.
6. Then, we will iterate over the map and if the size of the second vector is >=2 for a particular unique string, we print out the vector.

Time Complexity : O(N*K) [Iterate over each string and create frequency array]
Space Complexity : O(N) [Map]

EXAMPLE:
Input : [cat, dog, god, tca]
Output : [[1,4],[2,3]] [Use 1-based indexing]

TODO : Find out why C++ is not allowing me to use unordered_map
*/

#include <iostream>
#include <vector>
#include <string>
#include <map>

#define RANGE 26

using namespace std;

string countingSort(string s)
{
    int n = s.length();
    vector<int> freqArray(RANGE, 0);

    for (int i = 0; i < n; i++)
        ++freqArray[s[i] - 'a'];

    for (int i = 1; i < RANGE; i++)
        freqArray[i] += freqArray[i - 1];

    char outputStr[n];
    for (int i = 0; i < n; i++)
    {
        outputStr[freqArray[s[i] - 'a'] - 1] = s[i];
        --freqArray[s[i]];
    }

    string sortStr(outputStr);
    return sortStr;
}

vector<vector<pair<int, string>>> groupAnagramsSorting(vector<string> strs)
{
    int n = strs.size();
    vector<string> sortStrs;

    for (int i = 0; i < n; i++)
        sortStrs.push_back(countingSort(strs[i]));

    map<string, vector<int>> M;

    for (int i = 0; i < n; i++)
    {
        auto iter = M.find(sortStrs[i]);
        if (iter != M.end())
            iter->second.push_back(i);
        else
            M.insert({sortStrs[i], {i}});
    }

    vector<vector<pair<int, string>>> res;
    for (auto anagram : M)
    {
        vector<pair<int, string>> group = {};
        for (auto index : anagram.second)
        {
            pair<int, string> s = {make_pair(index, strs[index])};
            group.push_back(s);
        }
        res.push_back(group);
    }
    return res;
}

vector<vector<pair<int, string>>> groupAnagrams(vector<string> strs)
{
    int n = strs.size();
    // vector<int> - Stores frequency array
    // vector<pair<int,string>> - Stores a vector of pairs of the index of the string and the string itself.
    map<vector<int>, vector<pair<int, string>>> M;

    for (int i = 0; i < n; i++)
    {
        vector<int> freqArr(26, 0);
        int strLen = strs[i].length();
        for (int j = 0; j < strLen; j++)
            ++freqArr[strs[i][j] - 'a'];

        auto iter = M.find(freqArr);

        if (iter != M.end())
            iter->second.push_back(make_pair(i, strs[i]));
        else
        {
            vector<pair<int, string>> newGroup = {make_pair(i, strs[i])};
            M.insert({freqArr, newGroup});
        }
    }

    vector<vector<pair<int, string>>> res;
    for (auto it : M)
        res.push_back(it.second);

    return res;
}

int main(void)
{
    vector<string> strs = {"cat", "dog", "god", "tac", "run"};
    vector<vector<pair<int, string>>> res1 = groupAnagrams(strs);

    for (auto anagram : res1)
    {
        for (auto elem : anagram)
            cout << "[" << elem.first << ", " << elem.second << "] ";
        cout << "\n";
    }

    vector<vector<pair<int, string>>> res2 = groupAnagramsSorting(strs);
    for (auto anagram : res2)
    {
        cout << "\n";
        for (auto elem : anagram)
            cout << "[" << elem.first << ", " << elem.second << "] ";
    }

    return 0;
}
