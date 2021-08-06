// Given a circular array arr[] of N integers such that the last element of the given array is adjacent to the first element of the array, the task is to print the Next Greater Element in this circular array. Elements for which no greater element exist, consider the next greater element as "-1".
// https://www.youtube.com/results?search_query=next+greater+element+take+u+forward

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> nextGreaterElement(vector<int> V)
{
    stack<int> S;
    vector<int> Res;
    int n = V.size();

    for (int i = 2 * n - 1; i >= 0; i--)
    {
        while (!S.empty() && S.top() <= V[i % n])
            S.pop();

        if (i < n)
        {
            if (S.empty())
                Res.insert(Res.begin(), -1);
            else
                Res.insert(Res.begin(), S.top());
        }

        S.push(V[i % n]);
    }
    return Res;
}

int main()
{
    vector<int> V = {4, 12, 5, 3, 1, 2, 5, 3, 1, 2, 4, 6};
    vector<int> Res;
    Res = nextGreaterElement(V);
    for (int i = 0; i < Res.size(); i++)
        cout << Res[i] << " ";
    return 0;
}
