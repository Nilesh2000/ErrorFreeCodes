/*
Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

APPROACH 1: BRUTE-FORCE
Iterate over each triplet of the array and find the maximum product possible

Time Complexity : O(n^3)
Space Complexity : O(1)

APPROACH 2: SORTING
Sort the array in increasing order.
The product of the largest three numbers is not necessarily the largest product since the array may also contain negative integers.
There might be two negative intergers on the left extreme which when combined with the largest element may give us the maximum product.
Hence we have to return max(V[0]*V[1]*V[n-1], V[n-1]*V[n-2]*V[n-3])

Time Complexity : O(n*logn)
Space Complexity : O(1)

APPROACH 3: ONE-PASS
Declare 5 variables max1, max2, max3, min1, min2.
Iterate over the array and calculate the values for each of those variables.
Return max(min1*min2*max1, max1*max2*max3)

Time Complexity : O(n)
Space Complexity : O(1)

APPROACH 4 : HEAP
*/
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maximumProduct(vector<int> V)
{
    int max1, max2, max3;
    max1 = max2 = max3 = INT_MIN;
    int min1, min2;
    min1 = min2 = INT_MAX;

    for (auto num : V)
    {
        if (num >= max1)
        {
            max3 = max2;
            max2 = max1;
            max1 = num;
        }
        else if (num >= max2)
        {
            max3 = max2;
            max2 = num;
        }
        else if (num >= max3)
            max3 = num;

        if (num <= min1)
        {
            min2 = min1;
            min1 = num;
        }
        else if (num <= min2)
            min2 = num;
    }

    return max(max1 * max2 * max3, min1 * min2 * max1);
}

int main(void)
{
    vector<int> V = {-5, -6, 3, 2, 1, 4};
    cout << maximumProduct(V);
    return 0;
}
