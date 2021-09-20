/*
A farmer has built N stalls. (2 <= N <= 100000)
The stall are located on a straight line at positions x1, x2, ..., xN.

There are C number of cows (2 <= C <= N), which have to be placed in the stalls.
Assign the cows to the stalls in such a way that the minimum distance between any two of them is as large as possible.
Return the largest possible distance.

EXPLAINATION:
Let N=5, X[]={1,2,4,8,9} and C=3
Let us try to place the cows in their stalls.

|  1  |  2  |  4  |  8  |  9  |
   C1    C2    C3               (Minimum Distance = 2-1 = 1)
   C1          C2          C3   (Minumum Distance = 4-1 = 3)
   C1                C2    C3   (Minimum Distance = 9-8 = 1)
         C1    C2          C3   (Minimum Distance = 4-2 = 2)
   C1          C2    C3         (Minimum Distance = 4-1 = 3)

There will be more combinations, but for the sake of simplicity, we are considering only the above ones.
Thus, the largest minimum distance is 3.

APPROACH 1:
Recursively generate all combinations of the placement of 'C' cows and calculate the minimum distance in each of those cases.
Return the largest minimum distance.

APPROACH 2:
Sort the stalls array in increasing order.

This question uses the binary search algorithm.
The lowest possible largest distance is 1.
The highest possible largest distance is A[n - 1] - A[0].

Calculate Mid using the formula Low + (High-Low)/2.
Check if you can place 'C' cows by mainitaining a minimum distance of Mid between each of them.
If not, set High=Mid-1
If you can, store the Mid in Res and set Low=Mid+1 to maximize the minimum distance.

Time Complexity : O(N*LogN) (Sorting + (Binary Search*canPlaceCows))
Space Complexity : O(1)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canPlaceCows(vector<int> V, int numStalls, int numCows, int Dist)
{
    int coord = V[0];
    int Count = 1;
    for (int i = 1; i < numStalls; i++)
    {
        if (V[i] - coord >= Dist)
        {
            Count++;
            coord = V[i];
        }

        if (Count == numCows)
            return true;
    }
    return false;
}

int largestMinimumDistance(vector<int> V, int numStalls, int numCows)
{
    sort(V.begin(), V.end());

    int Low = 1;                        // Smallest possible largest minimum distance
    int High = V[numStalls - 1] - V[0]; // Biggest possible largest minimum distance
    int Res;

    while (Low <= High)
    {
        int Mid = Low + (High - Low) / 2;
        if (canPlaceCows(V, numStalls, numCows, Mid))
        {
            Res = Mid;
            Low = Mid + 1;
        }
        else
            High = Mid - 1;
    }
    return Res;
}

int main(void)
{
    int N = 5;
    vector<int> V = {1, 2, 8, 4, 9};
    int C = 3;
    cout << largestMinimumDistance(V, N, C);
    return 0;
}
