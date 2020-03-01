/*
A program to print the next smallest element for every element of an array.
Print -1 if no smaller element exists for that particular element.
Time Complexity : O(n^2)
*/
#include <iostream>
using namespace std;
void nextSmallestElement(int Arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    int nextSmallest = -1;
    for (int j = i + 1; j < n; j++)
    {
      if (Arr[j] < Arr[i])
      {
        nextSmallest = Arr[j];
        break;
      }
    }
    cout << nextSmallest << " ";
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
  cout << "Array of next smallest elements is : ";
  nextSmallestElement(Arr, n);
  cout << "\n";
  return 0;
}
