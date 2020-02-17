// https : //www.geeksforgeeks.org/find-missing-elements-of-a-range/
/*
Given an array arr[0..n-1] of distinct elements and a range [low, high], find all numbers that are in range, but not in array. The missing elements should be printed in sorted order.
Time complexity of first approach is O(nLogn + k) where k is number of missing elements 
(Note that k may be more than nlogn if array is small and range is big)
Time complexity of second solution is O(n + (high-low+1)).
If the given array has almost elements of range i.e., n is close to value of (high-low+1), then second approach is definitely better as there is no Log n factor. But if n is much smaller than range, then first approach is better as it doesn’t require extra space for hashing. We can also modify first approach to print adjacent missing elements as range to save time. For example if 50, 51, 52, 53, 54, 59 are missing, we can print them as 50-54, 59 in first method.
And if printing this way is allowed, the first approach takes only O(n Log n) time.
*/

#include <iostream>
#include <unordered_set>

using namespace std;

void findMissingInRange(int Arr[], int n, int Low, int High)
{
    unordered_set<int> S;
    for (int i = 0; i < n; i++)
        S.insert(Arr[i]);

    cout << "\nThe missing numbers in the range are : ";
    for (int i = Low; i <= High; i++)
    {
        if (S.find(i) == S.end())
        {
            cout << i << " ";
        }
    }
}

int main(void)
{
    int Arr[] = {1, 7, 12, 50, 54, 57};
    int Low = 50, High = 58;
    int n = sizeof(Arr) / sizeof(Arr[0]);
    findMissingInRange(Arr, n, Low, High);
    return 0;
}
