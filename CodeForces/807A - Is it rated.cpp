# include <iostream>
# include <algorithm>
# include <vector>
# include <numeric>
# include <cstring>
# include <set>
# include <cmath>

# define pb push_back

using namespace std;

int main(void) //Driver Function
{
  int n;
  cin >> n;
  pair <int, int> p[n];
    for(int i = 0 ; i < n ; i++)
      {
          cin >> p[i].first >> p[i].second;
      }
    for(int i = 0 ; i < n ; i++)
      {
          if(p[i].first != p[i].second)
            {
                cout << "rated" << endl;
                return 0;
            }
      }
    for(int i = 1 ; i < n ; i++)
      {
          for(int j = 0 ; j < i ; j++)
            {
                if(p[i].first > p[j].first)
                  {
                      cout << "unrated" << endl;
                      return 0;
                  }
            }
      }
  cout << "maybe" << endl;
  return 0;
}
//End Of Program
/*
How do we check if the round is rated for sure?
The round is rated for sure if anyone's rating has changed, that is, if ai ≠ bi for some i.
How do we check if the round is unrated for sure?
Given that all ai = bi, the round is unrated for sure if for some i < j we have ai < aj. This can be checked using two
nested for-loops over i and j.
How do we find that it's impossible to determine if the round is rated or not?
If none of the conditions from steps 1 and 2 is satisfied, the answer is "maybe".
*/
