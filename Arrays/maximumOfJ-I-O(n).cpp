// Given an array arr[], find the maximum j – i such that arr[j] > arr[i]
#include <iostream>
using namespace std;

int maxIndexDiff(int Arr[], int n)
{
  int *lMin = new int[(sizeof(int) * n)];
  int *rMax = new int[(sizeof(int) * n)];
  int maxJ, minI;

  // Construct lMin[] such that lMin[i] stores the minimum value from (Arr[0], Arr[1], ...., Arr[n-1])
  lMin[0] = Arr[0];
  for (int i = 1; i < n; i++)
    lMin[i] = min(Arr[i], lMin[i - 1]);

  //Construct rMax[] such that rMax[i] stores the maximum value from (Arr[n-1], Arr[n-2], ....., Arr[0])
  rMax[n - 1] = Arr[n - 1];
  for (int i = n - 2; i >= 0; i--)
    rMax[i] = max(Arr[i], rMax[i + 1]);

  int i = 0, j = 0, maxDiff = -1;
  while (i < n && j < n)
  {
    if (lMin[i] < rMax[j])
    {
      maxDiff = max(maxDiff, j - i);
      maxJ = j;
      minI = i;
      j++;
    }
    else
      i++;
  }
  cout << "\nj = " << maxJ << ", i = " << minI;
  cout << "\nArr[j] = " << Arr[maxJ] << ", Arr[i] = " << Arr[minI];
  return maxDiff;
}

int main(void)
{
  int n = 9;
  int Arr[] = {34, 8, 10, 3, 2, 80, 30, 33, 1};
  cout << "\nThe maximum difference of j - i such that Arr[j] >= Arr[i] is :  " << maxIndexDiff(Arr, n);
}
