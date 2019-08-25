# include <iostream>

using namespace std;

int removeDuplicates(int arr[], int n)
{
    if (n == 0 || n == 1) //If the array has no elements or 1 element, it has no duplicates.
        return n;

    int j = 0;
    for(int i = 0 ; i < n - 1 ; i++)  //Traverse till the second last element
    {
        if(arr[i] != arr[i + 1]) //If the two adjacent elements are dissimilar
        {
            arr[j] = arr[i]; //Store value of Arr[i] in Arr[j]
            j++; //increment j so that the next value be stored in the next index
        }
    }

    arr[j] = arr[n - 1]; //Store the last element in Arr[j]
    j++; //Increment j which is now the new size of the array. The number of elements in the array is j - 1.
    return j; //Return j as it is the new updated size.
}

//Driver function
int main(void)
{
    int Arr[] = {0, 0, 1, 1, 2, 3, 3, 4, 4, 4, 5};
    int n = sizeof(Arr) / sizeof(Arr[0]);
    n = removeDuplicates(Arr, n);
    cout << "\nArray after removing duplicates : ";
    for(int i = 0 ; i < n ; i++)
      cout << Arr[i] << " ";
    return 0;
}
//End of program
