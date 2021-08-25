/*
A is a row-wise sorted matrix with M rows and N columns.
It is guranteed that N*M is odd, thus there will be only one median element.
All elements are integers in the range of 1-10^9.
For a number to be a median, the number of matrix elements lesser than or equal to median should be equal to (N*M+1)/2

Approach:-
Copy all the matrix elements are store it in an array.
Sort the array.
Return the middle element of the array

Time Complexity : (N*M)log(N*M) [Because we will have N*M elements in the array]
Space Complexity : O(N*M)

Approach:-
Find the smallest and largest element in the matrix
That will be the range for binary search.
Find the middle element in the range of [minElement...maxElement]
Then, iterate through each row of the matrix and calculate the number of elements smaller than or equal to Mid.
If the number of such elements is lesser than (M*N+1/2), then median lies in [Mid+1...maxElement]
Else, median lies within [minElement...Mid]
Return minElement once minElement becomes greater than maxElement

Time Complexity of finding smallest and largest element : O(M)
Time Complexity of finding number of elements smaller than or equal to Mid for each row : O(M*log(N))
The largest possible maxElement will be the largest integer which is 2^32
So, worst case will be the search space from 1 to 2^32
So, worst case binary search will run 32 times

Total Time Complexity : O(M) + O(32*M*logN) ~ O(32*M*logN)
Space Complexity : O(1)
*/

#include <iostream>
#include <algorithm> // upper_bound
#include <climits>   // INT_MIN and INT_MAX
#define M 3
#define N 3

using namespace std;

int arrayMedian(int Arr[M][N])
{
    int minElement = INT_MAX, maxElement = INT_MIN;

    // Find the smallest and the largest element in the matrix
    // That will be our range for binary search
    for (int i = 0; i < M; i++)
    {
        if (Arr[i][0] < minElement)
            minElement = Arr[i][0];

        if (Arr[i][N - 1] > maxElement)
            maxElement = Arr[i][N - 1];
    }

    // Number of elements which should be greater than or equal to median
    int medianPos = (M * N + 1) / 2;

    // The lowest value maxElement can achieve is the median value. Once it achieves that value, minElement is increment until it becomes greater than or equal to maxElement. And hence, we return minElement at the end of each iteration
    while (minElement < maxElement)
    {
        int Mid = minElement + (maxElement - minElement) / 2;
        // count stores the number of elements in the matrix which are smaller than or equal to Mid
        int count = 0;

        // Find the number of elements smaller than the current Mid
        for (int i = 0; i < M; i++)
            // upper_bound returns the iterator of the first element greater than Mid
            // By subtracting that iterator from Arr[i], we can find the number of elements smaller than or equal to  Mid
            count += upper_bound(Arr[i], Arr[i] + N, Mid) - Arr[i];

        // If number of elements smaller than Mid is lesser than the desired, then median lies in the range of [Mid+1...maxElement]
        if (count < medianPos)
            minElement = Mid + 1;
        // If, number of elements greater than Mid is greater than or equal to desired, then median lies in the range of [minElement...Mid]
        else
            maxElement = Mid;
    }
    // At this point minElement becomes greater than or equal to maxElement, and hence we return minElement
    return minElement;
}

int main(void)
{
    int Arr[M][N] = {{10, 20, 30}, {20, 31, 40}, {50, 60, 70}};
    cout << arrayMedian(Arr);
    return 0;
}
