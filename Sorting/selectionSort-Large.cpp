#include <iostream>
using namespace std;

void selectionSortLarge(int n, int Arr[])
{
  int iLarge;
  for (int i = n - 1, k = 1; i >= 1; i--, k++)
  {
    iLarge = i;
    for (int j = n - k - 1; j >= 0; j--)
    {
      if (Arr[j] > Arr[iLarge])
      {
        iLarge = j;
      }
    }
    int Temp = Arr[i];
    Arr[i] = Arr[iLarge];
    Arr[iLarge] = Temp;
  }
}
int main(void)
{
  int n = 5;
  int Arr[] = {2, 4, 3, 1, 5};
  selectionSortLarge(n, Arr);
  for (int i = 0; i < n; i++)
    cout << Arr[i] << " ";
  return 0;
}
