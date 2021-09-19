/*
Give two sorted arrays, find the median of the resultant merged array.
For an array of even length, the averge of the elements at indices (n/2) and (n-1/2) will be the median of the array.
For an array of odd length, the element at index (n-1)/2 will be the median of the array.

Approach 1:-
Merge both the sorted arrays. Calculate the length of the resultant array.
Find the median of the resultant array.

Time Complexity : O(m+n)
Space Complexity : O(m+n)

Approach 2:
Calculate the index/indices of the median element(s).
Set k = 0
Iterate over both arrays and increment the count of k at every step as we try to arrive at the merged sorted array.
When k becomes equal to the median index/indices of the array, return the element(s) of the array at which the the k became equal to median index/indices.

Time Complexity : O(k)
Space Complexity : O(1)

Approach 3:-

CASE 1: COMBINED LENGTH OF BOTH ARRAYS IS EVEN
Let us assume arrays X[]={x1,x2,x3,x4,x5,x6} and Y[]={y1,y2,y3,y4,y5,y6,y7,y8}
After merging the total number of elements in the array will be 14.
Hence, the sorted array must have 7 elements in each half.

Let us assume that we find a partition such that x2<=y6 and y5<=x3.
Then, all elements before x2 will be lesser than or equal to y6.
Also, all elements before y5 will be lesser than or equal to x3.

Then, the first half will contain the elements {x1,x2,y1,y2,y3,y4,y5} (Not necessarily in that order)
The second half will contain the elements {x3,x4,x5,x6,y6,y7,y8} (Not necessarily in that order)

The median of the sorted array will be the average of the elements at indices (14-1)/2=6 and (14/2)=7
The element at index 6 will be the last element of the first half.
The element at index 7 will be the first element of the second half.

The max(x2, y5) will be the last element of the first half.
The min(x3,y6) will be the first element of the second half.

Hence, median will be avg(max(x2,y5), min(x3,y6))

CASE 2: COMBINED LENGTH OF BOTH ARRAYS IS ODD
Let us assume arrays X[]={x1,x2,x3,x4,x5,x6} and Y[]={y1,y2,y3,y4,y5,y6,y7}
After merging the total number of elements in the array will be 13.
Hence, the sorted array must have 7 elements in the left half and 6 in the right half.

Let us assume we find a partition such that x2<=y6.
Then, all elements before x2 will be lesser than or equal to y6.

Then, the first half will contain the elements {x1,x2,y1,y2,y3,y4,y5} (Not necessarily in that order)
The second half will contain the elements {x3,x4,x5,x6,y6,y7} (Not necessarily in that order)

The median in the sorted array will be the element at index (13/2)=6
The element at index 6 will be the last element of the first half.

The max(x2, y5) will be the last element of the first half.
Thus, the median is max(x2, y5).

ALGORITHM:
1. Perform binary search on the array of smaller length. Here, Low=0 and High=len(X)-1.
2. If you perform binary search on an array with more number of elements, then the below formula may return a negative values for some cases.
3. We will get a value Mid. Let us call it partitionX becuase we will try to partition X[] at that position.
4. Then value of partitionY will be partitionY=(x+y+1)/2 - partitionX. We will try to partition Y[] at that position.
5. We do the +1 so that is plays well with both odd and even lengths of the combined array.

Below, I am assuming X is array of smaller length.
6. if X[maxLeft] <= Y[minRight] && Y[maxLeft] <= X[minRight], then we have all the four required elements.
7. Else if X[maxLeft] > Y[minRight], move towards left in X. That is, High=Mid-1
8. Else if Y[maxLeft] > X[minRight], move towards right in X. That is, Low=Mid+1


EDGE CASE: 
We might end up having no on the leftX/leftY/rightX/rightY in some cases. That is, partitionX may become equal to 0 or n1.
In such a situation,
1. If the left half is empty, we consider the largest element to be -INF.
2. If the right half is empty, we consider the smallest element to +INF.

Time Complexity : O(log(min(x,y))) (x and y are lengths of arrays X[] and Y[])
Space Complexity : O(1)
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

double medianOfTwoSortedArrays(vector<int> V1, vector<int> V2)
{
    // We want to use the array of smaller length
    if (V1.size() > V2.size())
        return medianOfTwoSortedArrays(V2, V1);

    int n1 = V1.size(), n2 = V2.size();
    int Low = 0, High = n1;

    while (Low <= High)
    {
        int partitionX = Low + (High - Low) / 2;
        int partitionY = (n1 + n2 + 1) / 2 - partitionX;

        int maxLeftX = (partitionX == 0) ? INT_MIN : V1[partitionX - 1];
        int minRightX = (partitionX == n1) ? INT_MAX : V1[partitionX];

        int maxLeftY = (partitionY == 0) ? INT_MIN : V2[partitionY - 1];
        int minRightY = (partitionY == n2) ? INT_MAX : V2[partitionY];

        if (maxLeftX <= minRightY && maxLeftY <= minRightX)
        {
            // Length of merged sorted array is odd
            if ((n1 + n2) % 2 != 0)
                return ((double)max(maxLeftX, maxLeftY));

            // Length of merged sorted array is even
            else
            {
                int m1 = max(maxLeftX, maxLeftY);
                int m2 = min(minRightX, minRightY);
                return ((double)(m1 + m2) / 2);
            }
        }

        else if (maxLeftX > minRightY)
            High = partitionX - 1;

        else if (maxLeftY > minRightX)
            Low = partitionX + 1;
    }
    return -1;
}

int main(void)
{
    vector<int> V1 = {1, 3, 8, 9, 15};
    vector<int> V2 = {7, 11, 18, 19, 21, 25};

    // vector<int> V1 = {23, 26, 31, 35};
    // vector<int> V2 = {3, 5, 7, 9, 11, 16};

    cout << medianOfTwoSortedArrays(V1, V2);
    return 0;
}
