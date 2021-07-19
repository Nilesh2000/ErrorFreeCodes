/*
Given a sorted array and a value x, find the ceil of x.
The floor of x is the smallest element in array larger than or equal to x.
Write an efficient function to find ceil of x.
*/
#include <iostream>

using namespace std;

int ceilOfAnElement(int Arr[], int Low, int High, int Num)
{
    if (Num > Arr[High])
        return -1;

    if (Num <= Arr[Low])
        return Arr[0];

    while (Low <= High)
    {
        int Mid = (Low + High) / 2;
        if (Arr[Mid] == Num)
            return Mid;

        else if (Arr[Mid] < Num)
        {
            if (Mid + 1 <= High && Num <= Arr[Mid + 1])
                return Mid + 1;
            else
                return ceilOfAnElement(Arr, Mid + 1, High, Num);
        }

        else if (Arr[Mid] > Num)
        {
            if (Mid - 1 >= Low && Num > Arr[Mid - 1])
                return Mid;
            else
                return ceilOfAnElement(Arr, Low, Mid - 1, Num);
        }
    }
    return -1;
}

int main(void)
{
    int Arr[] = {1, 2, 4, 7, 9, 13, 17};
    int n = sizeof(Arr) / sizeof(Arr[0]);
    int x1 = 11; //Set x1 as 0 to execute else condition.
    int Index1 = ceilOfAnElement(Arr, 0, n - 1, x1);
    if (Index1 == -1)
        cout << "\nCeil of " << x1 << " does not exist in the array.";
    else
        cout << "\nCeil of " << x1 << " is : " << Arr[Index1];
    return 0;
}
