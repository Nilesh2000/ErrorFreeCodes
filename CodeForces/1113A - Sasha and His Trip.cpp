//Header Files
# include <bits/stdc++.h>

# define pb push_back

using namespace std;

int main(void) //Driver Function
{
  ios_base::sync_with_stdio(false);
  int n, v;
  /*
  n is the number of cities.
  v is the fuel capacity.
  To travel to n cities, you need a fuel capacaity of n - 1 litres.
  */
  cin >> n >> v;
    if(n - 1 <= v) //Thus, if the fuel capcity is greater than or equal to n-1, then required fuel will only be (n-1) litres.
      {
          cout << n - 1 << endl;
          return 0;
      }

  /*
  Else you must notice, that it is optimal to fill the tank as soon as possible, because if you don't do that, you will have to spend more money
  in future. So to drive first v − 1 kilometers just buy v − 1 liters in the first city, then to drive between cities with numbers i and i + 1,
  buy liter in the city with number i − v + 1.
  */

  int Res = v - 1; //Initialize Res to v - 1 as that is the amount of litres to filled in the first city.

    for(int i = 1 ; i <= n - v ; i++) //n - v refers to the number of litres yet to be filled.
      {
          Res += i;
      }
  cout << Res << endl;
  return 0;
}
//End Of Program
