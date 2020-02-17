#include <iostream>
using namespace std;

int equiliburumIndex(int Arr[], int n)
{
  int arraySum = 0, leftSum = 0;
  for (int i = 0; i < n; i++)
    arraySum += Arr[i];
  for (int i = 0; i < n; i++)
  {
    arraySum -= Arr[i];
    if (leftSum == arraySum)
    {
      return i;
    }
    leftSum += Arr[i];
  }
  return -1;
}

int main(void)
{
  int n;
  cout << "\nEnter the size of the array : ";
  cin >> n;
  int Arr[n];
  cout << "Enter the elements of the array : ";
  for (int i = 0; i < n; i++)
  {
    cin >> Arr[i];
  }

  int Index = equiliburumIndex(Arr, n);
  if (Index != -1)
    cout << Arr[Index] << " is the equiliburum element of the array.";
  else
    cout << "Equiliburum index does not exist for the array.";
}
