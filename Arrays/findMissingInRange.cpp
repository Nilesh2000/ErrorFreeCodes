/*
Given an array arr[0..n-1] of distinct elements and a range [low, high], find all numbers that are in range, but not in array. The missing elements should be
printed in sorted order.
*/
# include <iostream>
# include <unordered_set>

using namespace std;

void findMissingInRange(int Arr[], int n, int Low, int High)
{
    unordered_set <int> S;
    for(int i = 0 ; i < n ; i++)
      S.insert(Arr[i]);

    cout << "\nThe missing numbers in the range are : ";
    for(int i = Low ; i <= High ; i++)
    {
        if(S.find(i) == S.end())
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
