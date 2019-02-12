# include <iostream>
# include <cstring>
using namespace std;
int main()
{
  string s;
  char Ch;
  cin >>s;
   for(int i=0;i<s.length();i++)
    {
      Ch=tolower(s[i]);
       if(Ch=='a' || Ch=='e' || Ch=='y' || Ch=='u' || Ch=='o' || Ch=='i')
        {
          continue;
        }
       else
        {
          cout <<'.' <<Ch;
        }
    }
  return 0;
}
