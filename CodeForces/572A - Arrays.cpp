//Header Files
# include <bits/stdc++.h>

using namespace std;

int main(void) //Driver Function
{
    int a, b, k, m;
    cin >> a >> b >> k >> m;
    int Arr1[a], Arr2[b];
      for(int i = 0 ; i < a ; i++)
        {
          cin >> Arr1[i];
        }
      for(int i = 0 ; i < b ; i++)
        {
            cin >> Arr2[i];
        }
//If it's possible, then it's possible to choose k smallest elements in A and m largest elements in B. That means that
//in particular, k-th smallest element of A is less than m-th largest element in B. So, if A[k-1] < B[n - m] then
//the answer is "YES" and if not, then the answer is "NO".

//Basically you have to check if the largest element of Arr1 is lesser than the smallest element of Arr2 staring from b-m.
      if(Arr1[k - 1] < Arr2[b - m])
        {
            cout << "YES" << endl;
        }
      else
        {
            cout << "NO" << endl;
        }
    return 0;
}
//End Of Program
//https://codeforces.com/blog/entry/19923
