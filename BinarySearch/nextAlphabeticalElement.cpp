// Given a list of sorted characters consisting of both Uppercase and Lowercase Alphabets and a particular target value, say K, the task is to find the smallest element in the list that is larger than K.
// Letters also wrap around.For example, if K = ‘z’ and letters = [‘A’, ‘r’, ‘z’], then the answer would be ‘A’.
// This program is similar to finding the ceil of an element in a sorted array, except the fact that the elements here also wrap around

#include <iostream>
using namespace std;

int nextAlphabeticalElement(char Letters[], int Size, int Key)
{
    if (Key > Letters[Size - 1])
    {
        return Letters[0];
    }

    int Low = 0, High = Size - 1;
    int Result = -1;

    while (Low <= High)
    {
        int Mid = Low + (High - Low) / 2;
        if (Letters[Mid] > Key)
        {
            High = Mid - 1;
            Result = Mid;
        }
        else if (Letters[Mid] < Key)
        {
            Low = Mid + 1;
        }
    }
    return Letters[Result];
}

int main(void)
{
    char Letters[] = {'A',
                      'B',
                      'C',
                      'F',
                      'L',
                      'Z'};
    int Size = sizeof(Letters) / sizeof(Letters[0]);
    int Key = 'G';
    int nextAlphabet = nextAlphabeticalElement(Letters, Size, Key);
    cout << nextAlphabet;
    return 0;
}
