/*
Let there be a 100 doors in a hotel. All doors are closed initially.
Let the doors be labelled from 1, 2, 3,...100.

We perform 100 operations.
1. We toggle every door present in the hotel. That is, if it is closed we open it and vice versa.
2. We toggle every 2nd door.
3. We toggle every 3rd door.
.
.
100. We toggle every 100th door.
At every ith step, we toggle every ith door.

At the end of 100 steps, what are the numbers of the door which will remain open?

Let us simplify the problem.
Let N=10
    1   2   3   4   5   6   7   8   9   10
1   1   2   3   4   5   6   7   8   9   10
2   1   X   3   X   5   X   7   X   9   X
3   1   X   X   X   5   6   7   X   X   X
4   1   X   X   4   5   6   7   8   X   X
5   1   X   X   4   X   6   7   8   X   10
6   1   X   X   4   X   X   7   8   X   X
7   1   X   X   4   X   X   X   8   X   X
8   1   X   X   4   X   X   X   X   X   X
9   1   X   X   4   X   X   X   X   9   X
10  1   X   X   4   X   X   X   X   9   X

Here, we notice that every door is toggled when i is its factor.
And we know that factors come in pairs.
Hence, each door will be toggled an even number of times.
However, a perfect square has an odd number of factors.

Thus, all numbers which are perfect squares in the range of 1 to 100 will be open.
The number of perfect squares in the range of 1 to N is floor(sqrt(N))

Time Complexity : O(1)
Space Complexity : O(1)
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    int N = 100;
    cout << floor(sqrt(N));
    return 0;
}
