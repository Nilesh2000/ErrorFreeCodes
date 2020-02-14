//The bubble sort algorithm
//Best Case Time Complexity : O(N)
//Average Case Time Complexity : O(n^2)
//Worst Time Complexity : O(n ^ 2)
/*
The below is an optimized version of bubble sort.
If no swaps occur in an iteration, it means that the array has already been sorted and hence if the swapped flag is false, we break from the for llop.
*/
#include <iostream>
using namespace std;

void bubbleSort(int Arr[], int n)
{
    int Temp;
    for (int i = 0; i < n - 1; i++)
    {
        bool swapFlag = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (Arr[j] > Arr[j + 1])
            {
                Temp = Arr[j];
                Arr[j] = Arr[j + 1];
                Arr[j + 1] = Temp;
                swapFlag = true;
            }
        }
        if (swapFlag == false)
            break;
    }
}

int main(void)
{
    int Arr[] = {-3, 2, 1, 0, 5, -9, 6};
    int n = sizeof(Arr) / sizeof(Arr[0]);
    cout << "\nInitial Array : ";
    for (int i = 0; i < n; i++)
        cout << Arr[i] << " ";
    bubbleSort(Arr, n);
    cout << "\nSorted Array : ";
    for (int i = 0; i < n; i++)
        cout << Arr[i] << " ";
    return 0;
}
//End of program
