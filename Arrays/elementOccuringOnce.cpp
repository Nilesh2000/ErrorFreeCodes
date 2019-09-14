/*
Given a array A, size N, of integers; every element appears twice except for one. Find that element that appears once in array.
*/
# include <iostream>

using namespace std;

int main(void)
{
    int n;
    cout << "\nEnter size of array : ";
    cin >> n;
    int Arr[n];
    cout << "Enter elements of array : ";
    for(int i = 0 ; i < n ; i++)
      cin >> Arr[i];

    int Res = Arr[0];
    for(int i = 1 ; i < n ; i++)
      Res = Res ^ Arr[i];
    cout << "Element occuring once : " << Res << endl;
    return 0;
}
