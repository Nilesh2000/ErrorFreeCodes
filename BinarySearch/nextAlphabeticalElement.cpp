/*
Given a list of sorted characters consisting of both uppercase and lowercase alphabets and a particular target value, say k, the task is to find the first alphabet in the list that occurs lexicographically after k. 
Letters also wrap around.
For example, if k = ‘z’ and letters = [‘A’, ‘r’, ‘z’], then the answer would be ‘A’.
This program is similar to finding the ceil of an element in a sorted array, except the fact that the elements here also wrap around.

Time Complexity : O(log n)
Space Complexity : O(1)
*/

#include <iostream>

using namespace std;

int nextAlphabeticalElement(char Letters[], int n, char Key)
{
    if (Key >= Letters[n - 1])
        return Letters[0];

    int Low = 0, High = n - 1;

    while (Low <= High)
    {
        int Mid = Low + (High - Low) / 2;

        if (Letters[Mid] > Key)
            High = Mid - 1;
        else
            Low = Mid + 1;
    }
    return Letters[Low];
}

int main(void)
{
    char Letters[] = {'B', 'C', 'D', 'F', 'L', 'Z'};
    int n = sizeof(Letters) / sizeof(Letters[0]);
    char Key = 'D';

    char nextAlphabet = nextAlphabeticalElement(Letters, n, Key);
    cout << nextAlphabet;

    return 0;
}
