//Header Files
# include <iostream>
# include <algorithm>
# include <vector>
# include <numeric>
# include <cstring>
# include <set>
# include <cmath>

using namespace std;

int main(void) //Driver Function
{
  int x, n, k;
  cin >> n >> k;
  set <int> A;
  A.insert(0);
    while(n--)
      {
          cin >> x;
          A.insert(x);
      }
  auto it = A.begin();
    for(int i = 0 ; i < k ; i++)
      {
          if(next(it) == A.end())
            {
                cout << 0 << endl;
            }
          else
            {
                cout << *next(it) - *it << endl;
                it = next(it);
            }

      }
  return 0;
}
//End Of Program
//https://pastebin.com/bpz1YxBe
