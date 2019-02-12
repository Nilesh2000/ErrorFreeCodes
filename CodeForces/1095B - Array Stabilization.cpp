//Header Files
# include <iostream>
# include <algorithm>

using namespace std;

int main(void) //Driver Function
{
    int n;
    cin >> n;
    int Arr[n];
      for(int i = 0 ; i < n ; i++)
        {
            cin >> Arr[i];
        }
    sort(Arr, Arr + n);
    cout <<min(Arr[n - 2] - Arr[0], Arr[n - 1] - Arr[1]);
    //First parameter is the case when the largest element is ignored.
    //Second parameter is the case when the smallest element is ignored.
    return 0;
}
//End Of Program
//It is easy to see that we always have to remove either minimum or maximum of the array. So we can sort the array and the
//answer will be min(a[n-1]−a[1],a[n-2]−a[0]).
//https://codeforces.com/blog/entry/64130
