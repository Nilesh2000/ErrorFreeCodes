/*
Given a list of n-1 integers and these integers are in the range of 1 to n. There are no duplicates in list. One of the integers is missing in the list.
Write an efficient code to find the missing integer.
*/
#include <iostream>

using namespace std;

int findMissing(int Arr[], int n)
{
    int Low = 0, High = n - 1, Mid;
    /*
    The logic here is that if the array is sorted and contains all the elements, then Arr[Pos] - Pos will be equal to 1.
    */
    while (High - Low > 1)
    {
        Mid = (Low + High) / 2;
        if ((Arr[Low] - Low) != (Arr[Mid] - Mid)) //If true, search towards left
            High = Mid;

        else if ((Arr[High] - High) != (Arr[Mid] - Mid)) //Else, search towards right
            Low = Mid;
    }
    return (Arr[Mid] + 1); //Return element at Mid + 1 as that will be the missing element. Mid will be the missing position.
}

//Driver function
int main(void)
{
    int Arr[] = {1, 2, 3, 4, 5, 6, 8};
    int Size = sizeof(Arr) / sizeof(Arr[0]);
    cout << "\nThe missing element is : " << findMissing(Arr, Size);
    return 0;
}
//End of program
