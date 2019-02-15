//A brute force solution having an O(N^3) time complexity.
# include <iostream>
# include <climits>

using namespace std;

int Maximum_Sum_Subarray(int Arr[], int n)
{
    int Ans = INT_MIN; //Intialize Ans to least possible value
      for(int sub_array_size = 1 ; sub_array_size <=n ; sub_array_size++) //Size of the sub-array may vary from 1 to n. Hence, the loop.
        {
            for(int start_index = 0 ; start_index < n ; start_index++) //The start index of the sub-array will be 0 initially.
              {
                  if(start_index + sub_array_size > n) //If the subarray exceeds array bounds
                    {
                        break;
                    }
                int Sum = 0;
                  for(int i = start_index ; i < (start_index + sub_array_size) ; i++) //Calculate sum of each sub-array
                    {
                        Sum += Arr[i];
                    }
                Ans = max(Ans, Sum); //Update the value of sum accordingly.
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
