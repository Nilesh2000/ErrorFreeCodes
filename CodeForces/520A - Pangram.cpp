//Header Files
# include <iostream>

using namespace std;

const int numOfAlphabets = 26;
int main(void) //Driver Function
{
  int n, Flag = 0;
  bool Arr[numOfAlphabets] = {false};
  char Ch;
  cin >>n;
    for (int i=0;i<n;i++)
      {
        cin >>Ch;
          if ( islower(Ch) )
            {
                Arr[Ch-'a'] = true;
            }
           else
            {
                Arr[Ch-'A'] = true;
            }
      }
     for (int i=0;i<numOfAlphabets;i++)
      {
          if (Arr[i] == false)
            {
                Flag = 1;
                 break;
            }
      }
     if (Flag == 0)
      {
          cout << "YES" << endl;
      }
     else
      {
          cout << "NO" << endl;
      }
  return 0;
}
//End Of Program
