#include <iostream>
using namespace std;
void sortArray(int Arr[], int n)
{
  // We use the concept of partition of quick sort
  int j = -1;
  for (int i = 0; i < n; i++)
  {
    if (Arr[i] < 1)
    {
      j++;
      swap(Arr[i], Arr[j]);
    }
  }
}
int main(void)
{
  int n;
  cout << "\nEnter size of binary array : ";
  cin >> n;
  cout << "Enter the elements of the array : ";
  int Arr[n];
  for (int i = 0; i < n; i++)
    cin >> Arr[i];
  sortArray(Arr, n);
  cout << "Sorted Array : ";
  for (int i = 0; i < n; i++)
    cout << Arr[i] << " ";
  cout << "\n";
  return 0;
}
