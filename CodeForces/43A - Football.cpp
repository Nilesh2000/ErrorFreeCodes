//Header Files
# include <iostream>
# include <cstring>

using namespace std;

int main(void) //Driver Function
{
    string Team, Win;
    int n, Goals = 0;
    cin >> n;
      while(n--)
        {
            if(Goals != 0)
              {
                  cin >> Team;
                    if(Team == Win)
                      {
                          Goals++;
                      }
                    else
                      {
                          Goals--;
                      }
              }
            else //When goals become equal to 0 (during the start or when both teams have hit equal goals), next input
                 //will be for the winning team only.
              {
                  cin >> Win;
                  Goals = 1;
              }
        }
    cout << Win << endl;
    return 0;
}
//End Of Program
