/*
A program to sort an Array using the quick sort algorithm.

Average Case Time Complexity : O(n log n)
Worst Case Time Complexity : O(n^2)
Space Complexity : O(1)

The algorithm here is to choose the last element of the array as a Pivot and to make sure that all the elements left of the pivot are lesser than them and all
the elements to the right of the pivot are greater than the pivot.
This process is repeated in a recursive fashion.
*/

#include <iostream>

using namespace std;

int Partition(int Arr[], int Start, int End)
{
    int Pivot = Arr[End]; //Set the pivot element to the last element of the sub-array.
    int partitionIndex = Start - 1;

    for (int i = Start; i < End; i++) //Run a loop from the start of the sub-array to the end of the sub-array.
    {
        if (Arr[i] <= Pivot) //If one of the elements of the sub array is lesser than the pivot
        {
            partitionIndex++;                  //Move the partition index forward by 1.
            swap(Arr[i], Arr[partitionIndex]); //Swap it with the element at partition index to make sure it reaches the beginning of the array.
        }
    }

    swap(Arr[++partitionIndex], Arr[End]); //Swap the element at partition index with the element at Arr[End] which happens to be the Pivot element.
    return partitionIndex;
}

//The recursive quick sort function.
void quickSort(int Arr[], int Start, int End)
{
    if (Start < End)
    {
        int partitionIndex = Partition(Arr, Start, End);
        quickSort(Arr, Start, partitionIndex - 1);
        quickSort(Arr, partitionIndex + 1, End);
    }
}

//Driver Program
int main(void)
{
    int Arr[] = {7, 4, 6, 2, 1, 3, 5};
    int n = sizeof(Arr) / sizeof(int);
    quickSort(Arr, 0, n - 1);
    cout << "\nSorted Array : ";
    for (int i = 0; i < n; i++)
    {
        cout << Arr[i] << " ";
    }
    return 0;
}
//End of program
