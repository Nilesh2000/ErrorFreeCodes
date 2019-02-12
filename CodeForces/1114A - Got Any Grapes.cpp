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
  int x, y, z, a, b, c;
  cin >> x >> y >> z >> a >> b >> c;
  a -= x;
    if(a < 0)
      {
          cout << "NO" << endl;
          return 0;
      }
  long long Sum = a + b;
  Sum -= y;
    if(Sum < 0)
      {
          cout << "NO" << endl;
          return 0;
      }
  Sum += c;
  Sum -= z;
    if(Sum < 0)
      {
          cout << "NO" << endl;
          return 0;
      }
  cout << "YES" << endl;
  return 0;
}
//End Of Program
