//An implementation Of Kadane's algorithm with time complexity O(n).
//This algorithm will be valid only if there is atleast one positve number present in the array.
# include <iostream>
# include <climits>

using namespace std;

//Since this algorithm assumes there is atleast one positve element present in the array, the minimum sum is always equal to zero.
int Maximum_Sum_Subarray(int Arr[], int n)
{
    int Ans = 0, Sum = 0;
      for(int i = 0 ; i < n ; i++)
        {
            if(Sum + Arr[i] > 0) //If The sum results in a bigger positve integer, increment sum.
              {
                  Sum += Arr[i];
              }
            else //Else just reset sum to 0.
              {
                  Sum = 0;
              }
          Ans = max(Ans, Sum);
        }
    return Ans;
}

int main(void)
{
    int Arr[] = {3, 2, -5, 1};
    int n = sizeof(Arr) / sizeof(Arr[0]);
    cout << "\nThe Maximum Sub-Array Sum Is : " << Maximum_Sum_Subarray(Arr, n);
    return 0;
}
