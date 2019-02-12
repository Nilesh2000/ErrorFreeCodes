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
  string s;
  int Count = 0;
  cin >> s;
  auto Found = s.find('1');
  cout << (Found != string::npos && count(s.begin() + Found, s.end(), '0') >=6 ? "yes" : "no");
  return 0;
}
//End Of Program
