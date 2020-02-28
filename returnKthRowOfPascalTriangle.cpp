//Given an integer n, return the nth row of the pascal triangle.
//The idea here is to iteratively update the array from end to the beginning.
// Uses only O(k) extra space
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
  int rowNumber;
  cout << "\nEnter the row number : ";
  cin >> rowNumber;
  vector<int> V(rowNumber + 1, 0);
  V[0] = 1;
  for (int i = 1; i <= rowNumber; i++)
  {
    for (int j = i; j >= 1; j--)
    {
      V[j] += V[j - 1];
    }
  }
  cout << "The binomial coefficients are : ";
  for (auto i = V.begin(); i != V.end(); i++)
    cout << *i << " ";
}
