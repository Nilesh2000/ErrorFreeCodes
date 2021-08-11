/*
The Next greater Element for an element x is the first greater element on the right side of x in the array.
Find the distance of each elements from its next greatest element
If the next greatest element does not exist just set the value to 0.

Time Complexity : O(n)
Space Complexity : O(n)
*/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> nextGreatestDistance(vector<int> Arr)
{
    int n = Arr.size();
    vector<int> V(n);
    stack<int> S;

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = Arr[i];
        while (!S.empty() && Arr[S.top()] <= curr)
            S.pop();

        if (S.empty())
            V[i] = 0;
        else
            V[i] = S.top() - i;
        S.push(i);
    }

    return V;
}

int main(void)
{
    vector<int> Arr = {30, 40, 20, 60};
    vector<int> V = nextGreatestDistance(Arr);
    for (auto it : V)
        cout << it << " ";
    return 0;
}
