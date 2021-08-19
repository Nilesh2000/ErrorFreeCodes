/*
Given the arrival and departure times of all trains that reach a railway station, the task is to find the minimum number of platforms required for the railway station so that no train waits. 
We are given two arrays that represent the arrival and departure times of trains that stop.

Ask the interviewer if the start time array is sorted or not

Sort both arrival and departure arrays
Set platformNeeded=1
Iterate from 1 to n on Arrival array and 0 to n on departure array
If A[i]<=D[j], increment platformNeeded and i
If A[i]>D[j], decrement platformNeeded and increment j
If platformNeeded > Res, set Res = platformNeeded

Time Complexity : O(2NlogN) + O(2N) ~ O(NLogN)
Space Complexity : O(1)
*/
#include <iostream>

using namespace std;

int minimumNumberOfPlatforms(vector<int> A, vector<int> D)
{
    int n = A.size();

    sort(A.begin(), A.end());
    sort(V.begin(), V.end());

    // 1 platform is needed initially
    int platformNeeded = 1;
    int Count = 1;

    // Iterator to traverse arrival array
    // We start the index 1 becuase train on index 0 has already arrived but we don't if it has left
    int i = 1;

    // Iterator to traverse departure array
    int j = 0;

    while (i < n && j < n)
    {
        if (A[i] <= D[j])
        {
            platformNeeded++;
            i++;
        }
        else if (A[i] > D[j])
        {
            platformNeeded--;
            j++;
        }

        if (platformNeeded > Count)
            Count = platformNeeded;
    }
    return Count;
}

int main(void)
{
    vector<int> A = {900, 940, 950, 1100, 1500, 1800};
    vector<int> D = {910, 1200, 1120, 1130, 1900, 2000};
    cout << minimumNumberOfPlatforms(A, D);
}
