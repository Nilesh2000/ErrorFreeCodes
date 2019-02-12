//Header Files
# include <bits/stdc++.h>

using namespace std;

int main(void) //Driver Function
{
    int a, n, Sum = 0, Crimes = 0;
    cin >> n;
    //Maintain a variable, sum. Initially sum=0, it keeps the number of currently free police officers. With every recruitment
    //operation, add the number of officers recruited at that time to sum. When a crime occurs, if sum > 0 then decrease
    //the number of free officers by one, otherwise no officers are free so the crime will go untreated.
      while(n--)
        {
            cin >> a;
              if(a > 0)
                {
                    Sum += a;
                }
              else if(a == -1)
                {
                    if(Sum > 0)
                      {
                          Sum--;
                      }
                    else
                      {
                          Crimes++;
                      }
                }
        }
    cout << Crimes << endl;
    return 0;
}
//End Of Program
//https://codeforces.com/blog/entry/12082
