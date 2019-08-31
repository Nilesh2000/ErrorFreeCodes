//Given a sorted list of integers, square the elements and give the output in sorted order.
# include <iostream>
# include <cmath>

using namespace std;

void sortSquares(int Arr[], int n)
{
  /*
  We first partition the array into two halves. That is, we find out where tha last negative element occurs.
  */
  int k;
    for(k = 0 ; k < n ; k++)
    {
        if(Arr[k] >= 0)
        {
            break;
        }
    }

    int i = k - 1; //Index of the last negative number
    int j = k; //Index of the first positve number
    int Index = 0; //Initial index of the to be created array
    int Temp[n]; //Create a temporary array to store the sorted array of squares

    //Merge the two arrays based on the values of their squares
    while(i >= 0 && j < n)
    {
        if(pow(Arr[i], 2) > pow(Arr[j], 2))
        {
            Temp[Index] = pow(Arr[j], 2);
            j++;
        }
        else
        {
            Temp[Index] = pow(Arr[i], 2);
            i--;
        }
        Index++;
    }
    //At the end of this while loop, only one of the below 2 while loops will be executed.

    while(i >= 0)
    {
        Temp[Index] = pow(Arr[i], 2);
        Index++;
        i--;
    }
    while(j < n)
    {
        Temp[Index] = pow(Arr[j], 2);
        Index++;
        j++;
    }

    int Iter = 0;
    //Transfer all elements from temporary array to the original array.
    while(Iter < n)
    {
        Arr[Iter] = Temp[Iter];
        Iter++;
    }
}

void printArray(int Arr[], int n)
{
    for(int i = 0 ; i < n ; i++)
      cout << Arr[i] << " ";
}

int main(void)
{
    int Arr[] = {-9, -2, 0, 2, 3};
    int n = sizeof(Arr) / sizeof(Arr[0]);
    cout << "\nInitial Array : ";
    printArray(Arr, n);
    sortSquares(Arr, n);
    cout << "\nSorted Array of squares : ";
    printArray(Arr, n);
    return 0;
}
//End of program
