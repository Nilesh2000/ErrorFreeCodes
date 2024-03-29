/*
A program to find the bitonic element of a bitonic sequence.
A Bitonic Point is a point in bitonic sequence before which elements are strictly increasing and after which elements are strictly decreasing.
If there is no bitonic point, return -1, else return the bitonic element.

This problem can also be considered as an extension of counting the number of times a sorted array in descending order was rotated.
*/

#include <iostream>
#include <vector>

using namespace std;

int findBitonicElement(vector<int> V)
{
    if (Start <= End)
    {
        int Mid = Start + (End - Start) / 2;

        if (Arr[Mid] < Arr[Mid + 1])
            return findBitonicElement(Arr, Mid + 1, End);

        else if (Arr[Mid] < Arr[Mid - 1])
            return findBitonicElement(Arr, Start, Mid - 1);

        else
            return Arr[Mid];
    }
    return -1;
}

int main(void)
{
    vector<int> V = {1, 2, 3, 4, 3, 2, 1};
    /*
    We start from the second element and not the first because the first element cannot be a bitonic element.
    Similarly, we start with the second last element rather than the first element.
    */
    cout << findBitonicElement(Arr, 1, n - 2);
    return 0;
}
