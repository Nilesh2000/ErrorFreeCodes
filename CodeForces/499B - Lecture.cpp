//Header Files
# include <iostream>
# include <cstring>

using namespace std;

int main(void) //Driver Function
{
    int n, m;
    cin >> n >> m;
    string l1[m], l2[m], Lecture[n], Notes[n];
      for(int i = 0 ; i < m ; i++)
        {
            cin >> l1[i] >> l2[i];
        }
      for(int i = 0 ; i < n ; i++)
          {
              cin >> Lecture[i];
          }
      for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0; j < m ; j++)
              {
                  if(Lecture[i].compare(l1[j]) == 0)
                    {
                        Notes[i] = (l1[j].length() <= l2[j].length() ? l1[j] : l2[j]);
                         break;
                    }
              }
        }
      for(int i = 0 ; i < n ; i++)
        {
            cout << Notes[i] << " ";
        }
    return 0;
}
//End Of Program
