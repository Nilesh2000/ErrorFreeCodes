/*
Given a sorted array A (sorted in ascending order), having N integers, find if there exists any pair of elements (A[i], A[j]) such that their sum is equal to X.
Time Complexity : O(n)
*/
# include <iostream>

using namespace std;

/*
The algorithm basically uses the fact that the input array is sorted. We start the sum of extreme values (smallest and largest) and conditionally move both
pointers. We move left pointer i when the sum of A[i] and A[j] is less than X. We do not miss any pair because the sum is already smaller than X. Same logic
applies for right pointer j.
*/
void findPairs(int Arr[], int n, int Target)
{
    int i = 0, j = n - 1;

    while(i < j)
    {
        if(Arr[i] + Arr[j] == Target)
        {
          cout << Arr[i] << " " << Arr[j];
          return ;
        }
        else if(Arr[i] + Arr[j] < Target)
          i++;
        else
          j--;
    }
}

//Driver program
int main()
{
    int Arr[] = {1, 4, 7, 11, 12, 13, 15};
    int n = sizeof(Arr) / sizeof(Arr[0]);
    int Sum = 18;
    findPairs(Arr, n, Sum);
    return 0;
}
//End of program
