//A program to count the number of 1s in a non-increasing sorted array (consisting of 0s and 1s only) using binary search.
//Time Complexity : O(log n)
#include <iostream>

using namespace std;

int countOf1s(int Arr[], int Low, int High)
{
    if (High >= Low)
    {
        int Mid = Low + (High - Low) / 2; //Used instead of (Low+High)/2 to avoid integer overflow.

        //If the middle element is 1, and the next element is 0 , then number of 1s will be Mid+1
        // The second or condition (Mid == High) comes into play if the array consists of 1s only
        if ((Arr[Mid] == 1) && (Arr[Mid + 1] == 0 || Mid == High))
        {
            return Mid + 1;
        }
        else if (Arr[Mid] == 0) //If Arr[Mid] is 0, then continue searching towards the left of the array.
        {
            return countOf1s(Arr, Low, Mid - 1);
        }
        else //Else, continue searching towards the right of the array.
        {
            return countOf1s(Arr, Mid + 1, High);
        }
    }
    return 0;
}

int main(void) //Driver fuction
{
    int Arr[] = {1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0};                        //Array to count number of 1s
    int n = sizeof(Arr) / sizeof(int);                                       //n is the variable which is used to store the size of the array.
    cout << "The count of 1 in the array is : " << countOf1s(Arr, 0, n - 1); //Function call
    return 0;
}
