//Header Files
# include <iostream>
# include <algorithm>
# include <vector>
# include <numeric>
# include <cstring>
# include <set>
# include <cmath>

# define pb push_back

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
  int Cur = 1;
  sort(Arr, Arr + n);
    for(int i = 0 ; i < n ; i++)
      {
          if(Arr[i] >= Cur)
            {
                Cur++;
            }
      }
  cout << Cur << endl;
  return 0;
}
//End Of Program
//https://codeforces.com/problemset/problem/682/B?mobile=false
