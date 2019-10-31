//Insertion Sort Algorithm
//This is the best algorithm to sort an amost sorted array
//Time Complexity : O(n ^ 2)
# include <iostream>
using namespace std;

void insertionSort(int Arr[], int n)
{
    for(int i = 1 ; i < n ; i++)
    {
        int j = i - 1;
        int Temp = Arr[i];
        while(j >= 0 && Arr[j] > Temp)
        {
          Arr[j + 1] = Arr[j];
          j--;
        }
        Arr[j + 1] = Temp;
    }
}

int main(void)
{
    int Arr[] = {-3, 2, 1, 0, 5, -9, 6};
    int n = sizeof(Arr) / sizeof(Arr[0]);
    cout << "\nInitial Array : ";
    for(int i = 0 ; i < n ; i++)
      cout << Arr[i] << " ";
    insertionSort(Arr, n);
    cout << "\nSorted Array : ";
    for(int i = 0 ; i < n ; i++)
        cout << Arr[i] << " ";
    return 0;
}
//End of program.
