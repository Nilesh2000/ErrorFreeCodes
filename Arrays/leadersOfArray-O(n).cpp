#include <iostream>
#include <climits>
using namespace std;

void leadersOfArray(int Arr[], int n)
{
  int maxFromRight = INT_MIN;
  int leadersArr[n];
  int leadersIndex = 0;
  for (int i = n - 1; i >= 0; i--)
  {
    if (maxFromRight < Arr[i])
    {
      leadersArr[leadersIndex] = Arr[i];
      leadersIndex++;
      maxFromRight = Arr[i];
    }
  }
  for (int i = 0; i < leadersIndex; i++)
    cout << leadersArr[i] << " ";
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
