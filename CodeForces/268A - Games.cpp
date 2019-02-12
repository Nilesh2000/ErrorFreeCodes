//Header Files
# include <iostream>

using namespace std;

int main(void) //Driver Function
{
  int n, Count=0;
  cin >>n;
  int i, j, h[n], g[n];
      for (i=0; i<n; i++)
       {
          cin >> h[i] >> g[i];
       }
     for (i=0; i<n; i++)
      {
          for (j=0; j<n; j++)
            {
                if( (i != j) && (h[i]==g[j]) ) //i should not be equal to because we are not supposed to check for jerseys
                                               //of the same team.
                  {
                      Count++;
                  }
            }
      }
  cout <<Count <<endl;
  return 0;
}
//End Of Program
