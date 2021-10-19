/*
Given three sorted arrays A, B, and C of not necessarily same sizes. 
Calculate the minimum absolute difference between the maximum and minimum number of any triplet A[i], B[j], C[k] such that they belong to arrays A, B and C respectively, i.e., minimize (max(A[i], B[j], C[k]) – min(A[i], B[j], C[k])).

EXAMPLE :
Input : V1 : [ 1, 4, 5, 8, 10 ]
        V2 : [ 6, 9, 15 ]
        V3 : [ 2, 3, 6, 6 ]
Output : 1

EXPLAINATION: 
When we select A[i] = 5, B[j] = 6, C[k] = 6, we get the minimum difference 
max(A[i], B[j], C[k]) - min(A[i], B[j], C[k])) = |6-5| = 1

OBSERVATION:
A[i], B[j] and C[k] have to be as near as possible.

APPROACH 1: BRUTE FORCE
1. Iterate over all possible triplets.
2. Maintain a min value and update it after each iteration.
3. Return the value of min.

Time Complexity : O(N^3)
Space Complexity : O(1)

APPROACH 2:
1. We have two terms in this equation:-
| Max - Min |. To minimize the value, we can:-
                a) Reduce value of Max
                b) Increase Value of Min

2. Since all the arrays are sorted in increasing order and the minimum elements of each of the arrays is the first element, we cannot REDUCE THE VALUE OF MAX. Hence, we have to proceed with (b).

3. Thus, at the beginning when elements are pointing to the first element of the respective arrays.
   Calculate the value of the equation. Keep track of the minimum value of the equation.
   We find the minimum value among the arrays and move the pointer forward in that array which consists of the minimum value.

4. Iterate till you reach the end of any one of the arrays.

Time Complexity : O(V1+V2+V3) ~ O(N)
Space Complexity : O(1)
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minimizeDifference(vector<int> V1, vector<int> V2, vector<int> V3)
{
    int n1 = V1.size(), n2 = V2.size(), n3 = V3.size();
    int minDiff = INT_MAX;

    int i, j, k;
    i = j = k = 0;

    while (i < n1 && j < n2 && k < n3)
    {
        int currDiff = abs(max(V1[i], max(V2[j], V3[k])) - min(V1[i], min(V2[j], V3[k])));
        minDiff = min(minDiff, currDiff);

        int minTerm = min(V1[i], min(V2[j], V3[k]));

        if (V1[i] == minTerm)
            i++;
        else if (V2[j] == minTerm)
            j++;
        else
            k++;
    }
    return minDiff;
}

int main(void)
{
    vector<int> V1 = {5, 8, 10, 15};
    vector<int> V2 = {6, 9, 15, 78, 89};
    vector<int> V3 = {2, 3, 6, 6, 8, 8, 10};

    cout << minimizeDifference(V1, V2, V3);

    return 0;
}
