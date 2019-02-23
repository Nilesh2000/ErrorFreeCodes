//Header Files
# include <bits/stdc++.h>

# define pb push_back

using namespace std;

int main(void) //Driver Function
{
  ios_base::sync_with_stdio(false);
  int a, b, n, Last = 0, Draw = 1;
  //Initializing Draw to as the case of (0, 0) is also considered a draw.
  cin >> n;
    while(n--)
      {
          cin >> a >> b;
            if(min(a, b) > Last)
              {
                  Draw += min(a, b) - Last;
              }
            if(a == b)
              {
                  Last = a;
              }
            else
              {
                  Last = max(a, b) - 1;
              }
      }
  cout << Draw << endl;
  return 0;
}
//End Of Program
