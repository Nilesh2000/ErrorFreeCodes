/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

EXPLAINATION:-

Let heights = {2, 1, 5, 6, 2, 3}

             ___
         ___|   |
        |   |   |
        |   |   |    ___
 ___    | 5 | 6 |___|   |
|   |___|   |   |   |   |
| 2 | 1 |   |   | 2 | 3 |
|___|___|___|___|___|___|       

The largest rectangle possible has an area of 10 units
             ___ 
            | 1 |
         ___|___|
        |       |
        |       |    ___
 ___    |  10   |___|   |
|   |___|       |   |   |
| 2 | 1 |       | 2 | 3 |
|___|___|_______|___|___|

APPROACH 1:
For every rectangle in the histogram, find the heights of the smallest rectangles on the left and right. 
Let the indices of the smallest elements on the left and right be 'a' and 'b' respectively.
Then width of the rectangle will be (b - a + 1).
Multiply it with the height of the rectangle.
Do this for all the elements and return the greatest area possible.

Time Complexity : O(N^2)
Space Complexity : O(1)

APPROACH 2:
Use stacks to get the next smallest and previous smallest element distances for each rectangle height.
Then, use the above formula to calculate and return the maximum area possible.

Time Complexity : O(N) + O(N) + O(N)
Space Complexity : O(N) + O(N)

APPROACH 3:
Use the concept of a monotonic stack.
Monotonic stack has all its elements either in monotonic increasing or decreasing order.

Time Complexity : O(N) + O(N)
Space Complexity : O(N)
*/

#include <iostream>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

vector<int> previousSmallerElementDistance(vector<int> V)
{
    int n = V.size();

    stack<int> S;
    vector<int> leftSmall(n);

    for (int i = 0; i < n; i++)
    {
        while (!S.empty() && V[S.top()] >= V[i])
            S.pop();

        if (S.empty())
            leftSmall[i] = 0;
        else
            leftSmall[i] = S.top() + 1;

        S.push(i);
    }
    return leftSmall;
}

vector<int> nextSmallerElementDistance(vector<int> V)
{
    int n = V.size();

    stack<int> S;
    vector<int> rightSmall(n);

    for (int i = n - 1; i >= 0; i--)
    {
        while (!S.empty() && V[S.top()] >= V[i])
            S.pop();

        if (S.empty())
            rightSmall[i] = n - 1;
        else
            rightSmall[i] = S.top() - 1;

        S.push(i);
    }
    return rightSmall;
}

int largestRectangleArea(vector<int> heights)
{
    int n = heights.size();

    vector<int> leftSmall = previousSmallerElementDistance(heights);
    vector<int> rightSmall = nextSmallerElementDistance(heights);

    int maxArea = 0;
    for (int i = 0; i < n; i++)
        maxArea = max(maxArea, heights[i] * (rightSmall[i] - leftSmall[i] + 1));

    return maxArea;
}

int largestRectangleAreaOptimal(vector<int> V)
{
    int n = V.size();
    int maxArea = 0;
    stack<int> S;

    for (int i = 0; i <= n; i++)
    {
        while (!S.empty() && (i == n || V[S.top()] >= V[i]))
        {
            int height = V[S.top()];
            S.pop();
            int width;
            if (S.empty())
                width = i;
            else
                width = i - S.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        S.push(i);
    }
    return maxArea;
}

int main(void)
{
    vector<int> V = {2, 1, 5, 6, 2, 3};
    cout << largestRectangleArea(V) << '\n';
    cout << largestRectangleAreaOptimal(V);
    return 0;
}
