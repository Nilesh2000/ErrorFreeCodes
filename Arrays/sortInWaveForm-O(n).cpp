#include <iostream>
using namespace std;
void sortWaveForm(int Arr[], int n)
{
  for (int i = 1; i < n - 1; i += 2)
  {
    if (Arr[i - 1] > Arr[i])
      swap(Arr[i - 1], Arr[i]);
    else if (Arr[i] < Arr[i + 1])
      swap(Arr[i], Arr[i + 1]);
  }
  cout << "Array in wave form : ";
  for (int i = 0; i < n; i++)
    cout << Arr[i] << " ";
}
int main(void)
{
  int n;
  cout << "\nEnter the number of elements in the array : ";
  cin >> n;
  int Arr[n];
  cout << "Enter the elements of the array : ";
  for (int i = 0; i < n; i++)
    cin >> Arr[i];
  sortWaveForm(Arr, n);
  return 0;
}
