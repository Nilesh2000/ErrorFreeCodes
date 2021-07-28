// Given an integer array nums sorted in non - decreasing order, return an array of the squares of each number sorted in non - decreasing order.
// Time Complexity : O(n)
#include <iostream>
#include <vector>

using namespace std;

vector<int> squareArray(vector<int> V)
{
    int l = 0, r = V.size() - 1;
    int i = V.size() - 1;
    vector<int> Res(V.size());

    while (l <= r)
    {
        if (abs(V[l]) > V[r])
        {
            Res[i--] = V[l] * V[l++];
        }
        else
        {
            Res[i--] = V[r] * V[r--];
        }
    }
    return Res;
}

int main(void)
{
    vector<int> V{-4, -2, -1, 0, 2, 4, 6};

    for (int i = 0; i < V.size(); i++)
        cout << V[i] << " ";
    cout << "\n";

    vector<int> Res = squareArray(V);

    for (int i = 0; i < Res.size(); i++)
        cout << Res[i] << " ";

    return 0;
}
