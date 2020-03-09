// C++ program to print common elements in three arrays
// Given three arrays sorted in non-decreasing order, print all common elements in these arrays.
#include <iostream>
using namespace std;
void commonInThree(int Arr1[], int Arr2[], int Arr3[], int n1, int n2, int n3)
{
  int i, j, k;
  i = j = k = 0;

  // Iterate through three arrays while all arrays have elements
  while (i < n1 && j < n2 && k < n3)
  {
    //If x = y and y = z, print any of them and move ahead in all arrays
    if (Arr1[i] == Arr2[j] && Arr2[j] == Arr3[k])
    {
      cout << Arr1[i] << " ";
      i++;
      j++;
      k++;
    }

    // x < y
    else if (Arr1[i] < Arr2[j])
      i++;

    // y < z
    else if (Arr2[j] < Arr3[k])
      j++;

    else
      k++;
  }
}

int main(void)
{
  int Arr1[] = {1, 5, 10, 20, 40, 80};
  int Arr2[] = {6, 7, 20, 80, 100};
  int Arr3[] = {3, 4, 15, 20, 30, 70, 80, 120};
  int n1 = sizeof(Arr1) / sizeof(Arr1[0]);
  int n2 = sizeof(Arr2) / sizeof(Arr2[0]);
  int n3 = sizeof(Arr3) / sizeof(Arr3[0]);
  commonInThree(Arr1, Arr2, Arr3, n1, n2, n3);
  return 0;
}
