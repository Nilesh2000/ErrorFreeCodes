//Header Files
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
  long long n, m;
  int x, y;
  cin >> n >> m;
  set <int> a, b;
    while(m--)
      {
          cin >> x >> y;
          a.insert(x);
          b.insert(y);
          cout << (n - a.size()) * (n - b.size()) << " ";
      }
  return 0;
}
//End Of Program
/*
The underlying principle here is that it does not matter where you place the rook on the chess board. There will always
be a constant number (n - a.size()) * (n - b.size()) of cells not under attack where size() refers to the number of
elements in the set. The number of elements in the set increases with the number of rooks placed on the chess board.
*/
