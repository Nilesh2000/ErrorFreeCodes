//Header Files
# include <bits/stdc++.h>

# define pb push_back

using namespace std;

int main(void) //Driver Function
{
  ios_base::sync_with_stdio(false);
  int n, Page;
  cin >> n;
  pair <int, int> p[n];
    for(int i = 0 ; i < n ; i++)
      {
          cin >> p[i].first >> p[i].second;
      }
  cin >> Page;
    for(int i = n - 1 ; i >= 0 ; i--)
      {
          if(p[i].first <= Page)
            {
                cout << n - i << endl;
                return 0;
            }
      }
  return 0;
}
//End Of Program
