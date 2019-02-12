//Header Files
# include <iostream>
# include <algorithm>
# include <vector>
# include <numeric>
# include <cstring>

# define pb push_back

using namespace std;

bool isVowel(char Ch)
{
    return Ch == 'a' || Ch == 'e' || Ch == 'i' || Ch == 'o' || Ch == 'u';
}
int main(void) //Driver Function
{
  string s;
  cin >> s;
    for(int i = 0 ; i < s.length() ; i++)
      {
          if(!isVowel(s[i]) && !isVowel(s[i + 1]) && s[i] != 'n') //Only the letter n has special privelages.
            {
                cout << "NO" << endl;
                return 0;
            }
      }
  cout << "YES" << endl;
  return 0;
}
//End Of Program
