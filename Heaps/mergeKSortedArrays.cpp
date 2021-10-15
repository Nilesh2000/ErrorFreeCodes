/*
Given k sorted arrays of different sizes, merge them and print the sorted output.

APPROACH 1:
1. Iterate over each array element and push each one of them into a vector
2. Sort the vector

Time Complexity : O((N*K) + (N*K*log(N*K))
Space Complexity : O(1)

APPROACH 2:
1. Use a min-heap.
2. Insert the first element and the array number of each of the k-sorted arrays into the min-heap. [T.C : O(K)]
3. Iterate until the heap is not empty
    3.1 Pop the min element [T.C : O(1)]
    3.2 Push the min element to the result array. [T.C : O(log K)]
    3.3 Get the array number of the element which we just popped and insert the next element of that array into the heap.
    3.4 If the array has already been exhausted, ignore
4. Return resultant vector

Time Complexity : O(N*log(K))
Space Complexity : O(K) [To keep track of the last index we sorted in each of the k arrays]
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>> V)
{
    int k = V.size();

    // This vector is used to keep track of the last index we have sorted in each of the k arrays.
    // Initially, none of the indices are sorted. Hence, we set the value to be 0 for each of the k arrays.
    vector<int> idx(k, 0);

    // Initialize a min-heap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Insert the first element of each of the k-arrays into a min-heap
    for (int i = 0; i < k; i++)
        pq.push({V[i][0], i}); // Store the array element and the array number

    vector<int> R;

    while (!pq.empty())
    {
        // Get the smallest element of the min-heap
        pair<int, int> P = pq.top();
        pq.pop();

        R.push_back(P.first);

        // Get the array number of the element which we just popped and insert the next element of that array into the heap
        if (idx[P.second] + 1 < V[P.second].size())
            pq.push({V[P.second][idx[P.second] + 1], P.second});

        idx[P.second] += 1;
    }
    return R;
}

int main(void)
{
    vector<vector<int>> V = {{1, 4, 7}, {3, 5}, {2, 6, 7}};
    vector<int> R = mergeKSortedArrays(V);
    for (auto num : R)
        cout << num << " ";
    return 0;
}
