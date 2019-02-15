//A divide and conquer approach having O(n logn) time complexity.
# include <iostream>
# include <climits>

using namespace std;

/*
The underlying principle here is that we divide the array continuously into two parts until there is only one element left in the array.
After dividing into two parts, we compute the sum of the left half and right half separately using a recursive function.
*/

int Maximum_Sum_Subarray(int Arr[], int n)
{
      if(n == 1)
        {
            return Arr[0];
        }
    int m = n / 2;
    int Left_MSS = Maximum_Sum_Subarray(Arr, m);
    int Right_MSS = Maximum_Sum_Subarray(Arr, n - m);
    int leftSum = INT_MIN, rightSum = INT_MIN, Sum = 0;
      for(int i = (m - 1) ; i >= 0 ; i--)
        {
            Sum += Arr[i];
            leftSum = max(leftSum, Sum);
        }
    Sum = 0;
      for(int i = m ; i < n ; i++)
        {
            Sum += Arr[i];
            rightSum = max(rightSum, Sum);
        }
    int Ans = max(Left_MSS, Right_MSS);
    return max(Ans, leftSum + rightSum);
}

int main(void)
{
    int Arr[] = {3, -2, 5, 1};
    int n = sizeof(Arr) / sizeof(Arr[0]);
    cout << "\nThe Maximum Sub-Array Sum Is : " << Maximum_Sum_Subarray(Arr, n);
    return 0;
}
