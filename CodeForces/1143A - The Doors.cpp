//Header Files
# include <bits/stdc++.h>

# define pb push_back

using namespace std;

/*
The problem asks us calculate the minimum number indices of doors that are to be traversed before we can exit. We have to make sure all the doors
of any one exit have to open while exiting.
*/
 
int main(void) //Driver Function
{
  ios_base::sync_with_stdio(false);
  int a, b, n;
  cin >> n;
  int Arr[n];
    for(int i = 1 ; i <= n ; i++)
      {
          cin >> Arr[i];
            if(Arr[i] == 0)
              a = i;
            else
              b = i;
      }
  cout << min(a, b);
  return 0;
}
//End Of Program
