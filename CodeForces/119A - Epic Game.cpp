//Header Files
# include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    if(b == 0)
      return a;
   return gcd(b, a%b);
}
int main(void) //Driver Function
{
    int a, b, n, GCD1, GCD2;
    cin >> a >> b>> n;
      while(1)
        {
            GCD1 = gcd(a, n);
              if(n < GCD1)
                {
                    cout << 1 << endl;
                      break;
                }
            n -= GCD1;
            GCD2 = gcd(b, n);
              if(n < GCD2)
                {
                    cout <<0 << endl;
                      break;
                }
            n -= GCD2;
        }
    return 0;
}
//End Of Program
