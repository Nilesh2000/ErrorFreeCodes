/*
Given two sorted arrays of size m and n respectively, find the k'th position of the final sorted array.

Approach 1:-
Merge both the sorted arrays. Return the element at index k.

Time Complexity : O(m + n)
Space Complexity : O(m + n)

Approach 2:
Set cnt = 0
Iterate over both arrays and increment the count of 'cnt' at every step as we try to arrive at the merged sorted array.
When 'cnt' becomes equal to 'k', return the element(s) of the array at which the the k became equal to median index/indices.

Time Complexity : O(k)
Space Complexity : O(1)

Approach 3:
Let us assume there are two arrays X[] and Y[] of length n1 and n2.
We know that 1 <= k <= n1 + n2 and n1 < n2

Let us assume we partition the X[] at some index cutX.
Then, we will also partition Y[] at some index k - cutX.

If maxLeftX <= minRightY and maxRightY <= minLeftX, then the kth element will be the max(maxLeftX, maxRightY).

EDGE CASE 1: 
We might end up having no on the leftX/leftY/rightX/rightY in some cases. That is, partitionX may become equal to 0 or n1.
In such a situation,
1. If the left half is empty, we consider the largest element to be -INF.
2. If the right half is empty, we consider the smallest element to +INF.

EDGE CASE 2:
1. Let us assume that k > n2. That means the maximum number of elements we can pick from Y[] is n2 and hence we will have to pick a minimum of k - n2 elements from X[]. Hence, Low = max(0, k - n2).
2. Let us assume k < n1. That means the maximum number of elements we can pick from X[] is k. Hence, High = min(k, n1).

Time Complexity : O(log K)
Space Complexity : O(1)
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int kthSmallestOfTwoSortedArrays(vector<int> V1, vector<int> V2, int k)
{
    // We want to use the array of smaller length
    if (V1.size() > V2.size())
        return kthSmallestOfTwoSortedArrays(V2, V1, k);

    int n1 = V1.size(), n2 = V2.size();
    int Low = max(0, k - n2), High = min(k, n1);

    while (Low <= High)
    {
        int partitionX = Low + (High - Low) / 2;
        int partitionY = k - partitionX;

        int maxLeftX = (partitionX == 0) ? INT_MIN : V1[partitionX - 1];
        int minRightX = (partitionX == n1) ? INT_MAX : V1[partitionX];

        int maxLeftY = (partitionY == 0) ? INT_MIN : V2[partitionY - 1];
        int minRightY = (partitionY == n2) ? INT_MAX : V2[partitionY];

        if (maxLeftX <= minRightY && maxLeftY <= minRightX)
            return max(maxLeftX, maxLeftY);

        else if (maxLeftX > minRightY)
            High = partitionX - 1;

        else if (maxLeftY > minRightX)
            Low = partitionX + 1;
    }
    return -1;
}

int main(void)
{
    vector<int> V1 = {-2, -1, 3, 5, 6, 8};
    vector<int> V2 = {0, 1, 2, 5, 9};
    int k = 4;
    // int k = 8;

    cout << kthSmallestOfTwoSortedArrays(V1, V2, k) << '\n';
    cout << kthSmallestOfTwoSortedArrays(V1, V2, V1.size() + V2.size() - k + 1);
    return 0;
}
