/*
There are 'n' piles of bananes. Each pile has piles[i] number of bananas.
The monkey hash 'h' hours to eat all bananas.
Since the monkey likes to eat slowly and utilize all the available hours, return the minimum integer 'k' such that she can eat all the bananas within 'h' hours.

The monkey can eat only a maximum of 'k' bananas every hour. If the pile has less than 'k' bananas, she eats all of them instead and will not eat any more bananas during this hour.

EXPLAINATION:
piles[] = {3,6,7,11} and h=8
When k=3, h=1+2+3+4=10
When k=5, h=1+2+2+3=8
When k=4, h=1+2+2+3=8
Though both k=4 and k=5 result in the same number of hours return k=4 since we have to return the minimum value of k.

1. The question uses Binary Search algorithm.
2. The monkey will consume a minimum of '1' banana every hour. (When, Sum of all bananas=h)
3. The monkey will consume a maximum of the largest number of a bananas in a pile. (When n=h)
4. Calculate Mid using the formula Low + (High-Low)/2.
5. Check if the monkey can eat Mid bananas every hour.
6. If the monkey can, set High=Mid-1 so that we can minimize the maximum number of bananas that the monkey can eat
7. If the monkey cannot, set Low=Mid+1

Time Complexity : O(N*LogN)
Space Complexity : O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossible(vector<int> piles, int h, int numBananas)
{
    int hours = 0;
    for (auto p : piles)
    {
        hours += (p / numBananas);
        if (p % numBananas != 0)
            hours++;

        if (hours > h)
            return false;
    }
    return true;
}

int minEatingSpeed(vector<int> &piles, int h)
{
    int Low = 1;
    int High = *max_element(piles.begin(), piles.end());
    int Res;
    while (Low <= High)
    {
        int Mid = Low + (High - Low) / 2;
        if (isPossible(piles, h, Mid))
        {
            Res = Mid;
            High = Mid - 1;
        }
        else
            Low = Mid + 1;
    }
    return Res;
}

int main(void)
{
    vector<int> V = {30, 11, 23, 4, 20};
    int h = 5;
    // int h = 6;

    cout << minEatingSpeed(V, h);

    return 0;
}
