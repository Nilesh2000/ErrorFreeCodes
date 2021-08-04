// Given an array consisting of N+1 elements in the range of [1,N], find the duplicate element
// Time Complexity : O(n)
// Space Complexity : O(1)
// A disadvantage here is that we change the contents of the original array
#include <iostream>
using namespace std;
int findDuplicate(int Arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (Arr[abs(Arr[i])] > 0)
        {
            Arr[abs(Arr[i])] = -1 * Arr[abs(Arr[i])];
        }
        else
        {
            return abs(Arr[i]);
        }
    }
}

int main(void)
{
    int Arr[] = {1, 2, 2, 3, 4};
    int n = sizeof(Arr) / sizeof(Arr[0]);
    cout << findDuplicate(Arr, n);
    return 0;
}
