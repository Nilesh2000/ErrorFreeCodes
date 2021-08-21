/*
Given weights and values of n items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
In Fractional Knapsack, we can break items for maximizing the total value of knapsack.

Sort in descending order of values/weight.
Iterate the sorted array and check if the current weight exceeds the maximum weight.
If it does not, increment existing weight by current weight.
If it does exceed, then perform a fractional division to determine how many units of the weight we have add to the knapsack.
Increment the value at each stage of the iteration.
Return the final value.

Time Complexity : O(NLogN) + O(N) ~ O(NLogN)
Space Complexity : O(1)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item
{
    int Value;
    int Weight;
};

bool compare(Item i1, Item i2)
{
    double r1 = (double)i1.Value / (double)i1.Weight;
    double r2 = (double)i2.Value / (double)i2.Weight;
    return r1 > r2;
}

int fractionalKnapsack(vector<int> V, vector<int> W, int maxWeight)
{
    int n = V.size();
    struct Item items[n];

    for (int i = 0; i < n; i++)
    {
        items[i].Value = V[i];
        items[i].Weight = W[i];
    }

    // Sort in descending order of value of Value/Weight
    sort(items, items + n, compare);

    int curWeight = 0;
    double finalValue = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (items[i].Weight + curWeight <= maxWeight)
        {
            curWeight += items[i].Weight;
            finalValue += items[i].Value;
        }
        else
        {
            int remainingWeight = maxWeight - curWeight;
            finalValue += (items[i].Value / (double)items[i].Weight) * (double)remainingWeight;
            break;
        }
    }
    return finalValue;
}

int main(void)
{
    vector<int> V = {60, 100, 120};
    vector<int> W = {10, 20, 30};
    int maxWeight = 50;
    cout << fractionalKnapsack(V, W, maxWeight);
    return 0;
}
