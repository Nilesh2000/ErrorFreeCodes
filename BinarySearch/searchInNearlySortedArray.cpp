#include <iostream>

using namespace std;

int searchInNearlySortedArray(int Arr[], int Low, int High, int k)
{
    if (Low <= High)
    {
        int mid = Low + (High - Low) / 2;

        if (Arr[mid] == k)
        {
            return mid;
        }
        else if (Arr[mid - 1] == k && mid > Low)
        {
            return mid - 1;
        }
        else if (Arr[mid + 1] == k && mid < High)
        {
            return mid + 1;
        }
        else if (Arr[mid] > k)
        {
            return searchInNearlySortedArray(Arr, Low, mid - 2, k);
        }
        else if (Arr[mid] < k)
        {
            return searchInNearlySortedArray(Arr, mid + 2, High, k);
        }
    }
    return -1;
}

int main(void)
{
    int Arr[] = {20,
                 30,
                 40,
                 60,
                 50,
                 70,
                 80};

    int len = sizeof(Arr) / sizeof(Arr[0]);
    int search = 50;
    int index = searchInNearlySortedArray(Arr, 0, len - 1, search);
    cout << search << " was found at index : " << index;
    return 0;
}
