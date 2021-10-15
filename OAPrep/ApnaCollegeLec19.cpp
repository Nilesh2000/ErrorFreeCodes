/*
You are given an unsorted array.
Replace all the values in the array with the indices they would be in if the array were to be sorted.

APPROACH 1:-
1. Create a vector of pairs which stores the element and its index.
2. Sort the vector of pairs by elements
3. Iterate over the input vector and set V[P[i].second] to i.
4. Return the vector
5. Stop

Time Complexity : O(N)
Space Complexity : O(N)

EXAMPLE:
V = {10, 16, 7, 14, 5, 3, 12, 9}
R = {4,  7,  2, 6,  1, 0, 5,  3}
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> replaceIndices(vector<int> V)
{
    vector<pair<int, int>> P;
    int n = V.size();

    for (int i = 0; i < n; i++)
        P.push_back(make_pair(V[i], i));

    sort(P.begin(), P.end());

    for (int i = 0; i < n; i++)
        V[P[i].second] = i;
    return V;
}

int main(void)
{
    vector<int> V = {10, 16, 7, 14, 5, 3, 12, 9};
    vector<int> R = replaceIndices(V);

    for (auto num : R)
        cout << num << " ";

    return 0;
}
