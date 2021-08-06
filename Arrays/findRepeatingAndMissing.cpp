// Given an unsorted array of size n, one number is missing and one number occurs twice in the array. Find both these numbers.

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

The rightmost set bit in the binary representation of a number is the position of the rightmost 1 when a binary number is read from right to left.
*/

#include <iostream>
using namespace std;

void findRepeatingAndMissing(int Arr[], int n)
{
    int xor1 = Arr[0];
    for (int i = 1; i < n; i++)
    {
        xor1 ^= Arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        xor1 ^= i;
    }

    // Get the rightmost set bit in set_bit_no
    int set_bit_no = xor1 & ~(xor1 - 1);
    int *x = new int();
    int *y = new int();

    // Partition the array elements into two sets by comparing rightmost set bit of xor1 with the bit at the same position in each element.

    for (int i = 0; i < n; i++)
    {
        if (Arr[i] & set_bit_no)
        { // If Arr[i] belongs to the first set
            *x = *x ^ Arr[i];
        }
        else
        {
            *y = *y ^ Arr[i];
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

    cout << "The Missing element is : " << *x;
    cout << "\nThe Repeating element is : " << *y;
}

int main(void)
{
    int Arr[] = {1, 3, 4, 4, 5};
    int n = sizeof(Arr) / sizeof(Arr[0]);
    findRepeatingAndMissing(Arr, n);
    return 0;
}
