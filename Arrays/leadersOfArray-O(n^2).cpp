#include <iostream>
#include <climits>
using namespace std;

void leadersOfArray(int Arr[], int n)
{
  int i, j;
  for (i = 0; i < n; i++)
  {
    for (j = i + 1; j < n; j++)
    {
      if (Arr[j] > Arr[i])
      {
        break;
      }
    }
    if (j == n)
      cout << Arr[i] << " ";
  }
}

int main(void)
{
  int n;
  cout << "\nEnter the size of the array : ";
  cin >> n;
  int Arr[n];
  cout << "Enter the elements of the array : ";
  for (int i = 0; i < n; i++)
    cin >> Arr[i];
  leadersOfArray(Arr, n);
  return 0;
}
