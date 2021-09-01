// Given an unsorted array of size n containing elements in the range of [1,n], one number is missing and one number occurs twice in the array. Find both these numbers.

/*
Approach 1 : HashMap
Store the frequency of each element in the array in the hashmap.
Then iterate on the hashmap from 1 to n, and find the element whose frequency is 2 and the element whose frequency is 0.
Time Complexity : O(n) + O(n)
Space Complexity : O(n)

Approach 2 : Sort Array
Sort the array and check if the element at that index is equal to index + 1.
If it is not, the element at the index is the repeating element and index + 1 is the missing element.
Time Complexity : O(nlogn) + O(n)
Space Complexity : O(1)

Approach 3 : XOR all elements of the array with elements in the range of [1,n]
https://www.youtube.com/watch?v=5nMGY4VUoRY&t=652s&ab_channel=takeUforward
Time Complexity : O(5n)
Space Complexity : O(1)

Approach 4 : Cyclic Sort
Will work only if the elements in the array are in the range of [1,n]
If V[i]!=i+1, V[i] will be the repeating numeber and i+1 will be the missing number

The rightmost set bit in the binary representation of a number is the position of the rightmost 1 when a binary number is read from right to left.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> findRepeatingAndMissing(vector<int> V)
{
    int n = V.size();
    int xor1 = V[0];

    for (int i = 1; i < n; i++)
        xor1 ^= V[i];

    for (int i = 1; i <= n; i++)
        xor1 ^= i;

    // Get the rightmost set bit in set_bit_no
    int set_bit_no = xor1 & ~(xor1 - 1);
    int *x = new int();
    int *y = new int();

    // Partition the array elements into two sets by comparing rightmost set bit of xor1 with the bit at the same position in each element.

    for (int i = 0; i < n; i++)
    {
        if (V[i] & set_bit_no)
        { // If V[i] belongs to the first set
            *x = *x ^ V[i];
        }
        else
        {
            *y = *y ^ V[i];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (i & set_bit_no)
        { // If i belongs to the first set
            *x = *x ^ i;
        }
        else
        {
            *y = *y ^ i;
        }
    }

    vector<int> V1 = {*x, *y};
    return V1;
}

vector<int> findRepeatingAndMissingCyclicSort(vector<int> V)
{
    int i = 0, n = V.size();
    while (i < n)
    {
        int correct = V[i] - 1;
        if (V[i] != V[correct])
            swap(V[i], V[correct]);
        else
            i++;
    }

    vector<int> V2;
    for (int i = 0; i < n; i++)
    {
        if (V[i] != i + 1)
        {
            V2.push_back(i + 1);
            V2.push_back(V[i]);
        }
    }
    return V2;
}

int main(void)
{
    vector<int> V = {1, 4, 3, 4, 5};

    vector<int> V1 = findRepeatingAndMissing(V);
    for (auto num : V1)
        cout << num << " ";
    cout << '\n';

    vector<int> V2 = findRepeatingAndMissingCyclicSort(V);
    for (auto num : V2)
        cout << num << " ";
    return 0;
}
