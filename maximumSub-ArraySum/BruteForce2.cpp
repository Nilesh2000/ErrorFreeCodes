//A brute force solution having an O(N^2) time complexity.
# include <iostream>
# include <climits>

using namespace std;

int Maximum_Sum_Subarray(int Arr[], int n)
{
    int Ans = INT_MIN;
      for(int start_index = 0 ; start_index < n ; start_index++) //Starting Index of each of the sub-array.
        {
            int Sum = 0;
              for(int sub_array_size = 1 ; sub_array_size <= n ; sub_array_size++) //Computing sum of each sub-array
                {
                    if(start_index + sub_array_size > n) //If the subarray exceeds bounds
                      {
                          break;
                      }
                  Sum += Arr[start_index + sub_array_size - 1]; //Value Of the sum is not computed again and again and instead stored.
                  //Subtarcting 1 in the index because the array is zero-indexed.
                  Ans = max(Ans, Sum); ////Update the value of sum accordingly.
                }
        }
    return Ans;
}

int main(void)
{
  int Arr[] = {3, -2, 5, 1};
  int n = sizeof(Arr) / sizeof(Arr[0]);
  cout << "\nThe Maximum Sub-Array Sum Is : " << Maximum_Sum_Subarray(Arr, n);
  return 0;
}
