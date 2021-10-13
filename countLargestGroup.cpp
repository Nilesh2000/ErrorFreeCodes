/*
Given an integer n. Each number from 1 to n is grouped according to the sum of its digits. 
Return how many groups have the largest size.

Constraints:
1 <= n <= 10^4

EXAMPLE:
Input: n = 13
Output: 4
Explanation: There are 9 groups in total, they are grouped according sum of its digits of numbers from 1 to 13:
[1,10], [2,11], [3,12], [4,13], [5], [6], [7], [8], [9]. There are 4 groups with largest size.

APPROACH:
1. The constraints here are the heart of the question.
2. Given that the largest input can be 10000.
3. Thus, the the largest sum of digits possible will be of the number 9999. Thus, largest sum is 36.
4. Hence, sum of the digits can be in the range from 1 to 36.
5. We thus maintain a counter to count the occurrences of each sum. At the same time, we also maintain a variable to track which sum occurs most often.
6. We then iterate over the count array to count the number of groups which have the count same as the count of the group whose sum occurs most often.

Time Complexity : O(N)
Space Complexity : O(37) ~ O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

int sumOfDigits(int n)
{
    int Sum = 0;
    while (n != 0)
    {
        Sum += n % 10;
        n /= 10;
    }
    return Sum;
}

int countLargestGroup(int n)
{
    vector<int> V(37);
    int maxSize = 1;
    for (int i = 1; i <= n; i++)
        maxSize = max(maxSize, ++V[sumOfDigits(i)]);

    int cnt = 0;
    for (int i = 0; i < 37; i++)
    {
        if (V[i] == maxSize)
            cnt++;
    }
    return cnt;
}

int main(void)
{
    int n = 13;
    cout << countLargestGroup(n);
    return 0;
}
