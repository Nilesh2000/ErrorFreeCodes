//Header Files
# include <iostream>
# include <algorithm>
# include <vector>
# include <numeric>
# include <cstring>

# define pb push_back

using namespace std;

int main(void) //Driver Function
{
  string Layout1, Layout2, Text;
  cin >> Layout1 >> Layout2 >> Text;
    for(int i = 0 ; i < Text.length() ; i++)
      {
          for(int j = 0 ; j < Layout1.length() ; j++)
            {
                if(isupper(Text[i]))
                  {
                      if(tolower(Text[i]) == Layout1[j])
                        {
                            Text[i] = toupper(Layout2[j]);
                             break;
                        }
                  }
                else if(islower(Text[i]))
                  {
                      if(Text[i] == Layout1[j])
                        {
                          Text[i] = Layout2[j];
                           break;
                        }
                  }
            }
      }
  cout << Text << endl;
  return 0;
}
//End Of Program
