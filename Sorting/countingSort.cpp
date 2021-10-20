/*
Counting sort is a sorting technique based on keys between a specific range. 
It works by counting the number of objects having distinct key values (kind of hashing). 
Then doing some arithmetic to calculate the position of each object in the output sequence.

EXAMPLE:
For simplicity, consider the data in the range 0 to 9. 
Input data: 1, 4, 1, 2, 7, 5, 2

1. Take a count array to store the count of each unique object.
   Index:     0  1  2  3  4  5  6  7  8  9
   Count:     0  2  2  0  1  1  0  1  0  0

2. Modify the count array such that each element at each index stores the sum of previous counts. 
  Index:      0  1  2  3  4  5  6  7  8  9
  Count:      0  2  4  4  5  6  6  7  7  7

3. Iterate over the input vector again. Get the count of each element. Store the element at the index of its count.
   Decrease the count of the element

   Output:    1  1  2  2  4  5  7

Time Complexity : O(N + Range)
Space Complexity : O(N + Range)

We can also apply this sorting algorithm to sort strings since strings can have only a maximum of 255 unique characters.

OBSERVATIONS:
1. Counting sort is efficient if the range of input data is not significantly greater than the number of objects to be sorted. 
   Consider the situation where the input sequence is between range 1 to 10K and the data is 10, 5, 10K, 5K. 
2. Counting sort can be extended to work for negative inputs also.

TODO : Implement for Negative Numbers
*/

#include <iostream>
#include <vector>

#define RANGE 9
using namespace std;

vector<int> countingSort(vector<int> V)
{
    int n = V.size();
    vector<int> count(RANGE + 1, 0);
    vector<int> output(n);

    for (auto num : V)
        ++count[num];

    for (int i = 1; i <= RANGE; i++)
        count[i] += count[i - 1];

    for (int i = 0; i < n; i++)
    {
        // We do -1 because we want to maintain 0-based indexing
        output[count[V[i]] - 1] = V[i];
        --count[V[i]];
    }
    return output;
}

int main(void)
{
    vector<int> V = {1, 4, 1, 2, 7, 5, 2};
    vector<int> S = countingSort(V);
    for (auto num : S)
        cout << num << " ";
    return 0;
}
