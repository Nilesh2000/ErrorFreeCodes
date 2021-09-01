/*
Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> allDuplicates(vector<int> V)
{
    int i = 0;
    int n = V.size();

    vector<int> Dup;

    while (i < n)
    {
        int correct = V[i] - 1;
        if (V[i] != V[correct])
            swap(V[i], V[correct]);
        else
            i++;
    }

    for (int i = 0; i < n; i++)
    {
        if (i != V[i] - 1)
            Dup.push_back(V[i]);
    }

    return Dup;
}

int main()
{
    vector<int> V = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> Dup = allDuplicates(V);

    for (auto num : Dup)
        cout << num << " ";

    return 0;
}
