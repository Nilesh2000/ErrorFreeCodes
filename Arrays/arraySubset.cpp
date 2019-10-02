//A program to check if an array is a subset of another array. The arrays are not neccesarily sorted and the elements can be assumed as distinct.
/*
if the array has duplicate elements, the following approach can be used-
Create a map to store the frequency of each distinct number present in A[]. Then we will check if each number of B[] is present in map or not. If present in
the map, we will decrement the frequency value for that number by one and check for the next number. If map value for any number becomes zero, we will erase
it from the map. If any number of B[] is not found in the map, we will set the flag value and break the loops and print No. Otherwise, we will print Yes.
*/

# include <iostream>
# include <unordered_set>

using namespace std;

bool isArraySubset(int Arr1[], int Size1, int Arr2[], int Size2)
{
    unordered_set <int> S;
    for(int i = 0 ; i < Size1 ; i++)
      S.insert(Arr1[i]);

    for(int i = 0 ; i < Size2 ; i++)
    {
        if(S.find(Arr2[i]) == S.end())
          return false;
    }
    return true;
}

int main(void)
{
    int Arr1[] = {11, 2, 7, 4, 8, 9};
    int Arr2[] = {4, 9, 11};
    int n1 = sizeof(Arr1) / sizeof(Arr1[0]);
    int n2 = sizeof(Arr2) / sizeof(Arr2[0]);

    if(isArraySubset(Arr1, n1, Arr2, n2) == true)
      cout << "\nArray 2 is a subset of Array 1.";
    else
      cout << "\nArray 2 is not a subset of Array 1";
    return 0;
}
