//A program to check if an array is sorted in ascending order using Recursion or iteration. 
# include <iostream>

using namespace std;

/*
Recursive
The logic here is:-
Check if the size of the array is 1 or 0. If so, the array is already sorted. This acts as the base condition.
Or, check if the last two elements are in sorted order. If not, exit from the function immediately.
Else, just call and continue to check for tha last two elements until n becomes 1 or 0.
*/

int checkForSort(int Arr[], int n)
{
    if(n == 1 || n == 0)
      return 1;

    else if(Arr[n - 2] > Arr[n - 1])
      return 0;

    return checkForSort(Arr, n - 1);
}

/*
Iterative
*/
bool checkArrayForSort(int Arr[], int n)
{
    if(n == 0 || n == 1)
      return true;

    for(int i = 1 ; i < n ; i++)
    {
        if(Arr[i] < Arr[i - 1])
        {
            return false;
        }
    }
    return true;
}

//Driver function
int main(void)
{
    int Arr[] = {1, 2, 3, 4, 5, 6, 7};
    int Size = sizeof(Arr) / sizeof(Arr[0]);
    cout << "\nRecursive : ";
    if(checkForSort(Arr, Size))
    {
        cout << "The array is sorted.\n";
    }
    else
    {
        cout << "The array is not sorted.\n";
    }
    cout << "Iterative : ";
    if(checkArrayForSort(Arr, Size))
    {
        cout << "The array is sorted.\n";
    }
    else
    {
        cout << "The array is not sorted.\n";
    }
    return 0;
}
//End of program
