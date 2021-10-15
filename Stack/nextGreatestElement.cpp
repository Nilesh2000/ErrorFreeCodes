/*
Given an array of size n, return an array of size n containing the next greater element for every element in the array.
The Next greater Element for an element x is the first greater element on the right side of x in the array.
Elements for which no greater element exist, consider the next greater element as -1.

APPROACH 1:-
Brute Force:
Use two loops.
Iterate along each element of the array and for each element iterate from i+1 till the end of the array to find the next greater element

Time Complexity : O(n^2)
Space Compexity : O(1)

APPROACH 2:-
Use A Stack.

Time Complexity : O(n)
Space Complexity : O(n)
https://www.youtube.com/watch?v=Du881K7Jtk8&ab_channel=takeUforward
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> nextGreaterElement(vector<int> V)
{
    stack<int> S;
    vector<int> R;
    int n = V.size();

    for (int i = n - 1; i >= 0; i--)
    {
        while (!S.empty() && S.top() <= V[i])
            S.pop();

        if (S.empty())
            R.insert(R.begin(), -1);

        else
            R.insert(R.begin(), S.top());

        S.push(V[i]);
    }
    return R;
}

int main()
{
    vector<int> V = {4, 12, 5, 3, 1, 2, 5, 3, 1, 2, 4, 6};
    vector<int> R;
    R = nextGreaterElement(V);
    for (auto num : R)
        cout << num << " ";
    return 0;
}
