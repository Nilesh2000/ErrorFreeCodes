/* 
Given 2 sorted arrays, find a path through the intersections that produces maximum sum and return the maximum sum.
Switch from one array to another only at common elements.
If no intersection element is present, take sum of all elements from array with greater sum.
int Arr1[] = [ 1, 5, 10, 15, 20, 25 ], n1 = 6;
int Arr2[] = [ 2, 4, 5, 9, 15 ], n2 = 5;
Output = 81
Explaination : -
We start with Arr2 since 2 > 1.
Sum=2
Sum=2+Arr2[1]=6
Sum=6=Arr2[2]=11
Now we make the switch,
Sum=11+Arr1[2]=21
Sum=21+Arr1[3]=36
Sum=36+Arr1[4]=56
Sum=56+Arr1[5]=81
*/
#include <iostream>
using namespace std;

/*
The reason we add the smaller array element to the sum is because we have to switch between two common elements and not between two common indices.
*/
int intersectionSum(int Arr1[], int n1, int Arr2[], int n2)
{
  int i = 0, j = 0;
  int Result = 0, Sum1 = 0, Sum2 = 0;
  while (i < n1 && j < n2) //Comapre array elements at each stage
  {
    if (Arr1[i] < Arr2[j])
      Sum1 += Arr1[i++];
    else if (Arr1[i] > Arr2[j])
      Sum2 += Arr2[j++];
    else
    {
      Result += max(Sum1, Sum2);
      Sum1 = Sum2 = 0;
      while (i < n1 && j < n2 && Arr1[i] == Arr2[j])
      {
        Result += Arr1[i];
        i++;
        j++;
      }
    }
  }

  // Add the remaining elements to the respective Sums.
  while (i < n1)
  {
    Sum1 += Arr1[i++];
  }
  while (j < n2)
  {
    Sum2 += Arr2[j++];
  }
  Result += max(Sum1, Sum2);
  return Result;
}

// Driver program
int main(void)
{
  int Arr1[] = {1, 5, 10, 15, 20, 25}, n1 = 6;
  int Arr2[] = {2, 4, 5, 9, 15}, n2 = 5;
  cout << "\nThe maximum intersection sum is : " << intersectionSum(Arr1, n1, Arr2, n2);
  return 0;
}
