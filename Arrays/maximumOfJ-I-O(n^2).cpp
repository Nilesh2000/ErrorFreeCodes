// Given an array arr[], find the maximum j – i such that arr[j] > arr[i]
#include <iostream>
using namespace std;

int maxDiff(int Arr[], int n)
{
  int maxDiff = -1, maxJ, minI;
  for (int i = 0; i < n; i++)
  {
    for (int j = n - 1; j > i; j--)
    {
      if (Arr[j] > Arr[i] && maxDiff < (j - i))
      {
        maxDiff = j - i;
        maxJ = j;
        minI = i;
      }
    }
  }
  cout << "\nj = " << maxJ << ", i = " << minI;
  cout << "\nArr[j] = " << Arr[maxJ] << ", Arr[i] = " << Arr[minI];
  return maxDiff;
}

int main(void)
{
  int n = 9;
  int Arr[] = {34, 8, 10, 3, 2, 80, 30, 33, 1};
  cout << "\nThe maximum difference of j - i such that Arr[j] >= Arr[i] is :  " << maxDiff(Arr, n);
}
