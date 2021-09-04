/*
Given a sorted array and a value x, find the ceil of x.
The ceil of x is the smallest element in array larger than or equal to x.
Write an efficient function to find ceil of x.

Time Complexity : O(log n)
Space Complexity : O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

int ceilOfAnElement(vector<int> V, int Num)
{
    int n = V.size();
    int Low = 0, High = n - 1;

    if (Num > V[High])
        return -1;

    if (Num <= V[Low])
        return 0;

    while (Low <= High)
    {
        int Mid = Low + (High - Low) / 2;
        if (V[Mid] == Num)
            return Mid;

        else if (V[Mid] > Num)
            High = Mid - 1;

        else
            Low = Mid + 1;
    }
    return Low;
}

int main(void)
{
    vector<int> V = {1, 2, 4, 7, 9, 13, 17};
    int x1 = 15;

    int Index = ceilOfAnElement(V, x1);

    if (Index == -1)
        cout << "Ceil Does Not Exist";
    else
        cout << V[Index];
    return 0;
}
