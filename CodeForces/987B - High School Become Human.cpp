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
  int x, y;
  double a, b;
  cin >> x >> y;
    if(x == y)
      {
          cout << "=" << endl; //Print = because if x = y, then x^y will always be equal to y^x.
          return 0;
      }
  a = y * log(x);
  b = x * log(y);
    if(a == b) //Also, check for a = b, because, for example 2^4 = 4^2, where x and y are not equal to each other.
      {
          cout << "=" << endl;
      }
    else if(a > b)
      {
          cout << ">" << endl;
      }
    else
      {
          cout << "<" << endl;
      }
  return 0;
}
//End Of Program
//Refer https://www.quora.com/What-is-the-solution-to-987B-on-Codeforces for an excellent explaination
