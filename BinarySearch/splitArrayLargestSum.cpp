/*
Given an array nums which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays.
Write an algorithm to minimize the largest sum among these m subarrays.
This program is the same as allocate minimum number of pages algorithm, except that the array may not be sorted here.

EXPLAINATION:
Let A[] = {7, 2, 5, 10, 8}, m = 2

Subarray Combinations:-
1. [7] = 7 and [2,5,10,8] = 25 (Max : 25)
2. [7,2] = 9 and [5,10,8] = 23 (Max : 23)
3. [7,2,5] = 14 and [10,8] = 18 (Max : 18)
4. [7,2,5,10] = 24 and [8] = 8 (Max : 24)
We have to minimize the largest sum among these subarrays. Thus, we have to return 18.

APPROACH
1. We have to use the binary search algorithm. Let size of array be n.
2. The smallest possible result will be the largest element of the array. (m = n)
3. The largest possible result will be the sum of all array elements (m = 1)
4. Calculate Mid using the formula Low + (High-Low)/2.
5. Check if Mid can be a candidate for minSum.
6. If true, set High=Mid-1 to check if Mid can be minimized.
7. Else set Low=Mid+1

Time Complexity : O(N*LogN)
Space Complexity : O(1)

https://www.youtube.com/watch?v=Ss9ta1zmiZo&ab_channel=CodingBlocks
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool isValid(vector<int> V, int m, int minSum)
{
    int Cnt = 1;
    int currSum = 0;
    for (auto num : V)
    {
        if (num > minSum)
            return false;

        if ((num + currSum) > minSum)
        {
            Cnt++;
            currSum = num;
            if (Cnt > m)
                return false;
        }
        else
            currSum += num;
    }
    return true;
}

int splitArray(vector<int> &V, int m)
{
    int Low = *max_element(V.begin(), V.end());
    int High = accumulate(V.begin(), V.end(), 0);
    int Res;
    while (Low <= High)
    {
        int Mid = Low + (High - Low) / 2;

        if (isValid(V, m, Mid))
        {
            Res = Mid;
            High = Mid - 1;
        }
        else
            Low = Mid + 1;
    }
    return Res;
}

int main(void)
{
    vector<int> V = {7, 2, 5, 10, 8};
    int m = 2;

    cout << splitArray(V, m);

    return 0;
}
