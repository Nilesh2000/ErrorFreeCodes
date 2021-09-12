/*
Given two integer unsorted arrays nums1 and nums2, return an array of their intersection. E
ach element in the result must be unique and you may return the result in any order.

APPROACH:
1. Insert all the elements of the first vector into a set.
2. Iterate over the second vector and insert all those elements which exist in the set into a vector. Erase the inserted element from the set.
3. Return the vector

Time Complexity : O(m + n)
Space Complexity : O(m)

FOLLOW UP 1:  Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.
APPROACH 1 :
1. Sort both the vectors
2. Use 2-pointer technique to insert elements into the result vector and return it.

Time Complexity : O(max(m, n) log(max(m, n)))
Space Complexity : O(m + n)

APPROACH 2 : 
1. Iterate over the first vector and store the frequency of each integer in a hash map.
2. Iterate over the second vector and if the number exist in the hash map, decrease its frequency and insert it into the result vector.
3. Return the result vector

Time Complexity : O(m + n)
Space Complexity : O(m + n)
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

vector<int> unionOfTwoArrays(vector<int> V1, vector<int> V2)
{
    unordered_set<int> S;
    for (auto num : V1)
        S.insert(num);

    for (auto num : V2)
        S.insert(num);

    vector<int> V(S.begin(), S.end());
    return V;
}

vector<int> intersectionOfArrays(vector<int> V1, vector<int> V2)
{
    unordered_set<int> S(V1.begin(), V1.end());
    vector<int> V;
    for (auto num : V2)
    {
        if (S.find(num) != S.end())
        {
            V.push_back(num);
            S.erase(num);
        }
    }
    return V;
}

vector<int> intersectionOfArraysFollowUp(vector<int> V1, vector<int> V2)
{
    unordered_map<int, int> M;
    vector<int> V;

    for (auto num : V1)
        M[num]++;
    for (auto num : V2)
    {
        if (--M[num] >= 0)
            V.push_back(num);
    }
    return V;
}

int main(void)
{
    vector<int> V1 = {1, 2, 2, 1};
    vector<int> V2 = {2, 2};

    vector<int> U = unionOfTwoArrays(V1, V2);
    vector<int> I1 = intersectionOfArrays(V1, V2);
    vector<int> I2 = intersectionOfArraysFollowUp(V1, V2);

    for (auto num : U)
        cout << num << " ";
    cout << "\n";

    for (auto num : I1)
        cout << num << " ";
    cout << "\n";

    for (auto num : I2)
        cout << num << " ";

    return 0;
}
