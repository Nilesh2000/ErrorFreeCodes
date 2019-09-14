/*
In an array of n + 1 elements, each element is in the range of 1 to n. If only one element is repeating, find the repeating element in O(1) space.
*/
# include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "\nEnter size of array : ";
    cin >> n;
    int Arr[n + 1], arraySum = 0;

    cout << "Enter elements of array : ";
    for(int i = 0 ; i <= n ; i++)
    {
      cin >> Arr[i];
      arraySum += Arr[i];
    }

    int Sum = (n * (n + 1)) / 2;
    cout << "Repeating element : " << arraySum - Sum;
    return 0;
}
