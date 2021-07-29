// Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).
// Time Complexity : O(n)
// Space Complexity : O(1)
#include <iostream>

using namespace std;

int main(void)
{
    int Arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(Arr) / sizeof(Arr[0]);

    for (int i = 1; i < n; i++)
    {
        Arr[i] += Arr[i - 1];
    }

    for (int i = 0; i < n; i++)
    {
        cout << Arr[i] << " ";
    }
    return 0;
}
