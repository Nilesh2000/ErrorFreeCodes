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
  if(Ch=='a' || Ch=='A' || Ch=='e' || Ch=='E' || Ch=='i' || Ch=='I' || Ch=='o' || Ch=='O' || Ch=='u' || Ch=='U')
    return true;
  else
    return false;
}

int main(void) //Driver Function
{
  string s, t;
  cin >> s >> t;
    if(s.length() != t.length())
      {
          cout << "No" << endl;
          return 0;
      }
      for(int i = 0 ; i < s.length() ; i++)
        {
            if( (isVowel(s[i]) && isVowel(t[i])) || (!isVowel(s[i]) && !isVowel(t[i])) )
              {
                  continue;
              }
            else
              {
                  cout << "No" << endl;
                  return 0;
              }
        }
  cout << "Yes" << endl;
  return 0;
}
//End Of Program
