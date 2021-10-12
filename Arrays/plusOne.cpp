/*
You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

APPROACH:
1. Increment the last digit by 1.
2. Iterate from last digits till second digit
    If digit[i]==10
        Set digit[i] to 0
        Increment digit[i-1] by 1
3. If digits[0]==10
        Set digits[0]=1
        Insert 1 at the beginning of the digits array
4. Return the updated vector

Time Complexity : O(K), K is the number of elements in the array
Space Complexity : O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int> V)
{
    V.back()++;
    int n = V.size();
    for (int i = n - 1; i > 0 && V[i] == 10; --i)
    {
        V[i] = 0;
        V[i - 1]++;
    }
    if (V[0] > 9)
    {
        V[0] = 0;
        V.insert(V.begin(), 1);
    }
    return V;
}

int main(void)
{
    vector<int> V = {1, 8, 9};
    // vector<int> V = {9, 9};
    vector<int> R = plusOne(V);
    for (auto num : R)
        cout << num;
    return 0;
}
