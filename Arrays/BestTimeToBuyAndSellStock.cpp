/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. 
If you cannot achieve any profit, return 0.

APPROACH 1:
Iterate i from 0 to length of vector
    Iterate j from i+1 to length of vector
        if V[j]-V[i] > maxProfit
            maxProfit = V[j] - V[i]

Time Complexity : O(N^2)
Space Complexity : O(1)

APPROACH 2:
Iterate i from 0 to length of vector.
For every element:
    Calculate the difference between that element and the minimum of all the values before that element and we are updating the maximum profit if the difference thus found is greater than the current maximum profit.
    If that array element is smaller than all array elements before it, we update it to be the smallest element.

Time Complexity : O(N)
Space Complexity : O(1)
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxProfitBruteForce(vector<int> V)
{
    int maxProfit = INT_MIN;
    int n = V.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (V[j] - V[i] > maxProfit)
                maxProfit = V[j] - V[i];
        }
    }
    return maxProfit;
}

int maxProfit(vector<int> V)
{
    int minPrice = INT_MAX;
    int maxProfit = 0;

    for (auto num : V)
    {
        if (num < minPrice)
            minPrice = num;
        else if (num - minPrice > maxProfit)
            maxProfit = num - minPrice;
    }
    return maxProfit;
}

int main(void)
{
    vector<int> V = {7, 1, 5, 3, 6, 4};
    // vector<int> V = {4, 4, 4, 4};
    cout << maxProfitBruteForce(V) << '\n';
    cout << maxProfit(V);
    return 0;
}
