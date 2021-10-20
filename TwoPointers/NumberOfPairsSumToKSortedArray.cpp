/*
Given an array of sorted integers, and a number k’, find the number of pairs of integers in the array whose sum is equal to 'k’.

APPROACH:
1. Use the two-pointer algorithm since this is a sorted array.
2. If V[Low] + V[High] == k, then caluclate the frequency of the integers at V[Low] and V[High]
3. The number of pairs we can make then is the product of the two frequencies.
4. If V[Low] is equal to V[High], then calculate the frequency of the element. Let it be Count
5. Since we have to select a pair of numbers from the given frequency, the formula will be (Count)C(2) which is (Count*(Count - 1))/2.

Time Complexity : O(N) [Since we are visiting each element only once]
Space Complexity : O(1)

Follow Up : Print the indexes of all the elements which sum up to 'k'
*/

#include <iostream>
#include <vector>

using namespace std;

int numberOfPairsWhichSumToK(vector<int> V, int k)
{
    int Low = 0, High = V.size() - 1;
    int c = 0;

    while (Low < High)
    {
        if (V[Low] + V[High] < k)
            Low++;
        else if (V[Low] + V[High] > k)
            High--;
        else
        {
            int x = V[Low], y = V[High], xIndex = Low, yIndex = High;

            while (Low < High && V[Low] == x)
                Low++;

            while (High >= Low && V[High] == y)
                High--;

            if (x != y)
                c += (Low - xIndex) * (yIndex - High);
            else
            {
                int Temp = (yIndex - xIndex + 1);
                c += (Temp * (Temp - 1)) / 2;
            }
        }
    }
    return c;
}

int main(void)
{
    vector<int> V = {1, 1, 1, 1};
    int k = 2;

    // vector<int> V = {1, 4, 4, 5, 5, 5, 6, 6, 11};
    // int k = 10;

    cout << numberOfPairsWhichSumToK(V, k);
    return 0;
}
