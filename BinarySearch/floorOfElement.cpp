/*
Given a sorted array and a value x, find the floor of x.
The floor of x is the largest element in array smaller than or equal to x.
Write an efficient function to find floor of x.

Time Complexity : O(log n)
Space Complexity : O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

int floorOfAnElement(vector<int> V, int Num)
{
    int n = V.size();
    int Low = 0, High = n - 1;

    if (Num >= V[High])
        return High;

    if (Num < V[Low])
        return -1;

    while (Low <= High)
    {
        int Mid = Low + (High - Low) / 2;

        if (V[Mid] == Num)
            return Mid;

        else if (V[Mid] < Num)
            Low = Mid + 1;
        else
            High = Mid - 1;
    }
    return High;
}

int main(void)
{
    vector<int> V = {1, 2, 4, 7, 9, 13, 17};
    int x1 = 12;
    int Index = floorOfAnElement(V, x1);

    if (Index == -1)
        cout << "Floor Does Not Exist";
    else
        cout << V[Index];

    return 0;
}
