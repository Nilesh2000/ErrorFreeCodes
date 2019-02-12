//Header Files
# include <iostream>
# include <algorithm>
# include <vector>
# include <numeric>
# include <cstring>
# include <set>

# define pb push_back

using namespace std;

int main(void) //Driver Function
{
  int n;
  string s;
  cin >> n >> s;
    if(s[0] == 'S' && s[n - 1] == 'F') //Since the manager finds San Francisco warmer, his final destination must be
                                      //San Francisco. Also, he finds San Franciso warmer only when he starts from
                                      //Seattle. Thus, his starting point must always be Seattle.
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
