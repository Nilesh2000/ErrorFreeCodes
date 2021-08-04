/*
Given a array A, size N, of integers; every element appears twice except for one. Find that element that appears once in array.
*/

/*
The logic here is that the XOR of a number with itself is 0.
And the XOR of a number with 0 is the number itself.
Thus, let us assume an array of numbers as follows:-
[1,2,1,2,3]
==> 1^2^1^2^3 = (1^1)^(2^2)^3 
              = (0)^(0)^3
              = 3
*/

/*
Another approach is to add all the numbers in the hash table, with the key being the number and the value being the number of occurences.
After inserting all the elements, we check which element occurs twice in the hash table.
*/
#include <iostream>

using namespace std;

int main(void)
{
  int n;
  cout << "\nEnter size of array : ";
  cin >> n;
  int Arr[n];
  cout << "Enter elements of array : ";
  for (int i = 0; i < n; i++)
    cin >> Arr[i];

  int Res = Arr[0];
  for (int i = 1; i < n; i++)
    Res = Res ^ Arr[i];
  cout << "Element occuring once : " << Res << endl;
  return 0;
}
