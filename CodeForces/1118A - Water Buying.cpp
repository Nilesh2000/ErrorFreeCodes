//Header Files
# include <bits/stdc++.h>

# define pb push_back

using namespace std;

int main(void) //Driver Function
{
  ios_base::sync_with_stdio(false);
  int Num;
  cin >> Num;
    while(Num--)
      {
          long long n, a, b;
          cin >> n >> a >> b;
          /*
          b refers to price of 2 litre bottles.
          a refers to price of 1 litre bottles.
          n refers to amount in litres to be filled.
          */
          cout << min(b * (n / 2) + (n % 2) * a, n * a) << endl;
          //Calculate minimum of the two quantities.
      }
  return 0;
}
//End Of Program
