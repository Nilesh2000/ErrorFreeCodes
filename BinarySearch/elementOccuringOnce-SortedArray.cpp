/*
Given a sorted array in which all elements occur twice (one after one) except one element which occurs once. 
Find that element in O(log n) time complexity.

APPROACH 1:
1. XOR all the elements of the array to get the element occurring only once.

Time Complexity : O(N)
Space Complexity : O(1)

APPROACH 2:
Logic :
Let the element we require be x.
We can also say that the index of x must be even only.

For all elements before x,
1. The First Occurrence of the element will be at indices such as [0,2,..] which are even indices
2. The Second occurrence will be at indices [1,3,...] which are odd indices.

For all elements after x,
1. The First Occurrence of the element will be at indices such as [7,9,..] which are odd indices
2. The Second occurrence will be at indices [8,10,...] which are even indices.

1. Take Low and High Pointer. 
2. Low Points to 0, High Points to end of array
3. Find Mid. 
4. Check if V[Mid] is the first occurrence of the number.
5. If not, find the first occurrence, and move the Low and High pointers accordingly.

Time Complexity : O(log n)
Space Complexity : O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int> V)
{
    int n = V.size();
    int Low = 0, High = n - 1, Mid;
    while (Low <= High)
    {
        Mid = Low + (High - Low) / 2;

        // Make sure Mid is pointing to the first occurrence of V[Mid]
        if (Mid > 0 && V[Mid - 1] == V[Mid])
            Mid--;

        // We will reach this condition only if V[Mid]!=V[Mid-1] or if Mid=0.
        // Thus, if below condition is true, it means that V[Mid] occurs once only.
        if (Mid < n - 1 && V[Mid + 1] != V[Mid])
            break;

        // Since Mid is an even index, and V[Mid] is the first occurrence, the element occuring once will come only after it.
        if (Mid % 2 == 0)
            Low = Mid + 2;
        // Since Mid is an odd index, and V[Mid] is the first occurrence, the element occuring once will come only before it.
        else
            High = Mid - 1;
    }
    return V[Mid];
}

int main(void)
{
    vector<int> V = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    cout << singleNumber(V);
    return 0;
}
