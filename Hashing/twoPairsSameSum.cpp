/*
Find four elements a, b, c and d in an array such that a+b = c+d

APPROACH 1:
1. Iterate over all possible combinations using 4 loops.
2. Check if for any condition a+b=c+d.
3. Return a,b,c,d if the condition is met.

Time Complexity : O(N^4)
Space Complexity : O(1)

APPROACH 2:
1. Iterate with two for loops at a time.
2. Compute the sum and store it in a hashmap.
3. The key of the hashmap will be the sum and the value will be the pair.
4. If the sum is already present in the map, we return M[sum] and V[i], V[j]
5. Else, we just insert the sum into the hash map.

Time Complexity : O(N^2)
Space Complexity : O(1)
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

pair<pair<int, int>, pair<int, int>> sum(vector<int> V)
{
    int n = V.size();
    unordered_map<int, pair<int, int>> M;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int sum = V[i] + V[j];

            if (M.find(sum) != M.end())
            {
                pair<int, int> P1 = M[sum];
                pair<int, int> P2 = make_pair(V[i], V[j]);
                return make_pair(P1, P2);
            }
            else
            {
                M.insert({sum, make_pair(V[i], V[j])});
            }
        }
    }
}

int main(void)
{
    vector<int> V = {3, 4, 7, 1, 2, 9, 8};
    pair<pair<int, int>, pair<int, int>> P = sum(V);

    cout << "[" << P.first.first << "," << P.first.second << "]";
    cout << " [" << P.second.first << "," << P.second.second << "]";

    return 0;
}
