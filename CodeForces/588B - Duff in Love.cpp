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
  ios_base::sync_with_stdio(false);
  long long n;
  cin >> n;
  long long x = n, Ans = 1;
    for(long long i = 2 ; i * i <= n ; i++)
      {
        if(x % i == 0)
          {
            Ans *= (long long)i;
              while(x % i == 0)
                {
                    x /= i;
                }
          }
      }
    if(x > 1)
      {
          Ans *= x;
      }
  cout << Ans << endl;
  return 0;
}
//End Of Program
//https://codeforces.com/blog/entry/20971
