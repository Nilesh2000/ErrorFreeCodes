//A program to implement the Merge Sort algorithm.
//Time Complexity : O(nlogn)
#include <iostream>

using namespace std;

void Merge(int *Arr, int *leftArr, int leftCount, int *rightArr, int rightCount)
{
    int i, j, k;
    /*
    i - Index of the left sub array.
    j - Index of the right sub array.
    k - Index of the merged sorted sub array.
    */
    i = j = k = 0;
    while (i < leftCount && j < rightCount)
    {
        if (leftArr[i] < rightArr[j])
        {
            Arr[k++] = leftArr[i++];
        }
        else
        {
            Arr[k++] = rightArr[j++];
        }
    }

    //At the end of the above while loop, only one of the below two while loops will be executed
    while (i < leftCount)
    {
        Arr[k++] = leftArr[i++];
    }
    while (j < rightCount)
    {
        Arr[k++] = rightArr[j++];
    }
}

void mergeSort(int *Arr, int n)
{
    int Mid, *leftArray, *rightArray;

    if (n < 2) //Keep dividing the array into two parts until there is only element in each of the sub-array. That is, keep dividing till n >= 2.
        return;
    Mid = n / 2;
    leftArray = (int *)malloc(Mid * sizeof(int));        //Allocate memory for left subarray
    rightArray = (int *)malloc((n - Mid) * sizeof(int)); //Allocate memory for right subarray

    for (int i = 0; i < Mid; i++)
    {
        leftArray[i] = Arr[i];
    }

    for (int i = Mid, j = 0; i < n; i++, j++)
    {
        rightArray[j] = Arr[i];
    }

    mergeSort(leftArray, Mid);                       //Call merge sort for leftArray recursively until sizeof the leftArray becomes less than 2.
    mergeSort(rightArray, n - Mid);                  //Call merge sort for rightArray recursively until sizeof the rightArray becomes less than 2.
    Merge(Arr, leftArray, Mid, rightArray, n - Mid); //Merge left and right subarray
    //Free the memory occupied by leftArray and rightArray so that they can be used again in the next recursive call.
    free(leftArray);
    free(rightArray);
}

int main(void)
{
    int Arr[] = {7, 6, 4, 2, 1, 3, 5};
    int n = sizeof(Arr) / sizeof(Arr[0]);
    mergeSort(Arr, n);
    cout << "\nSorted Array : ";

    for (int i = 0; i < n; i++)
    {
        cout << Arr[i] << " ";
    }

    return 0;
}
