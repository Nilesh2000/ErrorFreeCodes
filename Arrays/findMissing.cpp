// Given an array nums containing n distinct numbers in the range[0, n], return the only number in the range that is missing from the array.
// Time Complexity : O(n)
// Space Complexity : O(1)
#include <iostream>
#include <vector>
using namespace std;

int findMissing(vector<int> V)
{
    int n = V.size();
    int result = V.size();
    for (int i = 0; i < n; i++)
    {
        result ^= i;
        result ^= V[i];
    }
    return result;
}

int main(void)
{
    vector<int> V{4, 5, 1, 2, 0};
    cout << "The missing number in the range (0,n) is : " << findMissing(V);
    return 0;
}
