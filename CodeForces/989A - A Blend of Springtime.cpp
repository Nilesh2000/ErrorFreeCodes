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
	cin >> s;
	 for(int i = 1 ; i < s.length() - 1; i++)
    {
	     if( s[i - 1] != s[i] && s[i] != s[i + 1] && s[i - 1] != s[i + 1] && s[i] + s[i - 1] + s[i + 1] == 'A' + 'B' +'C' )
        {
	         return printf("Yes\n"), 0;
        }
    }
  return printf("No\n"),0;
}
//End Of Program
//https://codeforces.com/blog/entry/59968
