/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

OBSERVATION
We can trap water if there is a valley-like pattern in the elevation map. So the height of the bars should have a decrease, followed by an increasing height pattern to catch the rain. 

APPROACH:-
The solution here is that to calculate the amount of rainwater trapped at an element V[i].
We have to find the maximum element to the left of V[i]
We have to find the maximum element to the right of V[i].
And then, we have to calculate min(leftMax(V[i], rightMax(V[i])) - V[i]
We then return the sum of units of the rainwater trapped
 
Time Complexity : O(n^2)
Space Complexity : O(1)

Instead of finding the leftMax and rightMax for each V[i] when we encounter them, we can simply create an prefixMax and suffixMax array for the array elements and then we can access the leftMax and rightMax in O(1) time for each V[i].

Time Complexity : O(n) + O(n) + O(n) ~ O(n)
Space Complexity : O(n) + O(n) ~ O(n)

Two Pointer Approach:-
Time Complexity : O(n)
Space Complexity : O(1)

https://www.youtube.com/watch?v=m18Hntz4go8&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=43&ab_channel=takeUforward
*/

#include <iostream>
#include <vector>

using namespace std;

int trapWater(vector<int> V)
{
    int n = V.size();

    // Set Low and High
    int Low = 0;
    int High = n - 1;

    // Set maxLeft and maxRight
    int maxLeft = 0;
    int maxRight = 0;

    // Initially set total amount of rain water to be trapped is 0
    int Total = 0;

    while (Low <= High)
    {
        // We only have to worry about maxLeft here because if this condition is true we know there exists some element on the right of the current element that is greater than the elements on the left and we care only about min(maxLeft(A[i]), maxRight(A[i]))
        if (V[Low] <= V[High])
        {
            if (V[Low] >= maxLeft)
                maxLeft = V[Low];
            else
                Total += (maxLeft - V[Low]);
            Low++;
        }
        else
        {
            if (V[High] >= maxRight)
                maxRight = V[High];
            else
                Total += (maxRight - V[High]);
            High--;
        }
    }
    return Total;
}

int main(void)
{
    vector<int> V = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trapWater(V);
    return 0;
}
