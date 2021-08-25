// Given an unsorted array of size n containing n+1 elements within the range of [1,n], find the element which occurs more than once. It is guaranteed that there is only one element which occurs more than once.

/*
Approach :
Sort the array.
Iterate from [0..n-1]
Return true if A[i]==A[i+1]
This approach modifies the original array which is not favourable.

Time Complexity : O(N * LogN) + O(n) ~ O(N * LogN)
Space Compexity : O(1)

Approach : 
If the array has no duplicates, we can map each index to a number. That is, a mapping function f(index)=number
For example, for [2,1,3]
We start with index =0
f(0)=2
f(2)=3
We repeat this process until the index exceeds the array. (A[3] does not exist)
And hence there is no duplicate

If there is a duplicate in the array, say [2,3,1,3]
f(0)=2
f(2)=1
f(1)=3
f(3)=3
And hence, we get a cycle. The starting point of the cycle is the repeated number.

Step 1:
The array's indices are in [0, n]. The array's values are in [1, n]. This means nums[0] will lead us to an index that is in [1, n] (because nums[0] is a value). But nobody will lead us back to index 0 (because everyone's value is in [1, n] not including 0).

Step 2:
Starting from index 0, we can definitely reach a cycle. Why? By contradiction. If we cannot reach a cycle, that is to say, we always meet a new index, and then meet a new index, but there are only finite number of indices. So we will reach a cycle.

Step 3:
Then this cycle's entrace's index must be one duplicated number (because two guys lead us to it).

Step 4:
Since there is only one duplicated number, then that's it.

Proof:-
Let distance from head to start of loop be x
Distance from start of loop to meeting point be y
Distance from meeting point to start of loop be z.

Then,
Distance covered by slow pointer = x+y
Distance covered by fast pointer =x+2y+z
Then, 2(x+y)=x+2y+z
2x+2y=x+2y+z
x=z

Thus, when we reset slow to 0 and then move fast and slow by one step each, we will meet at the starting point of the loop.

Time Complexity : O(N)
Space Compexity : O(1)
*/
#include <iostream>

using namespace std;

int findRepeating(int Arr[], int n)
{
    // A repeated element can exist only if the size of the array is greater than 1
    if (n > 1)
    {
        int slow = Arr[0];
        int fast = Arr[Arr[0]];

        while (slow != fast)
        {
            slow = Arr[slow];
            fast = Arr[Arr[fast]];
        }

        slow = 0;
        while (slow != fast)
        {
            slow = Arr[slow];
            fast = Arr[fast];
        }
        return slow;
    }
    return -1;
}

int main(void)
{
    int n = 5;
    int Arr[n] = {1, 2, 2, 2, 4, 3};
    cout << findRepeating(Arr, n);
    return 0;
}
