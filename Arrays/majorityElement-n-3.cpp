// Given an array, find all the majority elements present in the array.
// A majority element in an array A[] of size n is an element that appears more than n / 3 times.
// Atmost 2 elements can occur n/3 times.

/*
APPROACH:-
Time Complexity : O(n)
Space Complexity : O(1)
https://www.youtube.com/watch?v=yDbkQd9t2ig&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=17&ab_channel=takeUforward
*/

#include <iostream>
#include <vector>

using namespace std;

void majorityElement(int Arr[], int n)
{
    int num1 = -1, num2 = -1, c1 = 0, c2 = 0;
    vector<int> V;

    for (int i = 0; i < n; i++)
    {
        if (num1 == Arr[i])
            c1++;
        else if (num2 == Arr[i])
            c2++;
        else if (c1 == 0)
        {
            num1 = Arr[i];
            c1 = 1;
        }
        else if (c2 == 0)
        {
            num2 = Arr[i];
            c2 = 1;
        }
        else
        {
            c1--;
            c2--;
        }
    }
    c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (Arr[i] == num1)
            c1++;
        else if (Arr[i] == num2)
            c2++;
    }

    if (c1 > n / 3)
        V.push_back(num1);
    if (c2 > n / 3)
        V.push_back(num2);

    if (V.empty() == false)
    {
        for (int i = 0; i < V.size(); i++)
            cout << V[i] << " ";
    }
    else
    {
        cout << "No Majority Element";
    }
}

int main(void)
{
    int Arr[] = {1, 1, 1, 3, 3, 2, 2, 2};
    int n = sizeof(Arr) / sizeof(n);
    majorityElement(Arr, n);
    return 0;
}
