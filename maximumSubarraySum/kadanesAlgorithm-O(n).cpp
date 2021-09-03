//An implementation Of Kadane's algorithm with time complexity O(n).
//This algorithm will be valid only if there is atleast one positve number present in the array.
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

//Since this algorithm assumes there is atleast one positve element present in the array, the minimum sum is always equal to zero.
int maximumSubarraySum(vector<int> V)
{
  int Ans = 0, Sum = 0;
  for (auto num : V)
  {
    if (Sum + num > 0) //If The sum results in a bigger positve integer, increment sum.
      Sum += num;

    else //Else just reset sum to 0.
      Sum = 0;

    Ans = max(Ans, Sum);
  }
  return Ans;
}

int main(void)
{
  vector<int> V = {3, 2, -5, 1};
  cout << maximumSubarraySum(V);
  return 0;
}
