//Header Files
# include <iostream>
# include <cstring>
# include <algorithm>

using namespace std;

bool compare(string &s1, string &s2) //Passing strings by reference because we want to see the change to be reflected
                                    //in tthe calling environment.
{
    return s1.length() < s2.length();
}
int main(void) //Driver Function
{
    int n, Flag = 1 ;
    cin >> n;
    string s[n];
      for(int i = 0 ; i < n ; i++)
        {
          cin >> s[i];
        }
    sort(s, s + n, compare);
    string subStr = s[0];
      for(int i = 1 ; i < n ; i++)
        {
             if(strstr(s[i].c_str(), subStr.c_str()) == 0)
               {
                  cout << "NO" << endl;
                  Flag = 0;
                  break;
               }
            subStr = s[i];
        }
      if(Flag == 1)
        {
            cout <<"YES";
              for(int  i = 0 ; i < n ; i++)
                {
                  cout << endl << s[i];
                }
        }
    return 0;
}
//End Of Program
