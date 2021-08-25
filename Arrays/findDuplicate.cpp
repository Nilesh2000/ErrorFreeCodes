// Given an array consisting of N+1 elements in the range of [1,N], one element of the array occurs twice.
// Find that duplicate element.

/*
XOR all the elemnts of the array
XOR the result with 1 to n-1
That will be the missing number

Time Complexity : O(2n) ~ O(n)
Space Complexity : O(1)
*/

#include <iostream>

using namespace std;

int findDuplicate(int Arr[], int n)
{
    int Res = Arr[0];

    for (int i = 1; i < n; i++)
        Res ^= Arr[i];

    for (int i = 1; i < n; i++)
        Res ^= i;

    return Res;
}

int main(void)
{
    int Arr[] = {2, 1, 2, 4, 3};
    int n = sizeof(Arr) / sizeof(Arr[0]);
    cout << findDuplicate(Arr, n);
    return 0;
}
