//Header Files
# include <bits/stdc++.h>

# define ll long long
# define pb push_back

using namespace std;

int main(void) //Driver Function
{
    int a, b, n, Ans = 0;
    cin >> n;
    //To cover a point (xi, yi), the length of the shorter side of the triangle should be at least xi + yi.
    //So the answer is max(xi + yi).
      while(n--)
        {
            cin >> a >> b;
            Ans = max(Ans, a + b);
        }
    cout << Ans << endl;
    return 0;
}
//End Of Program
//https://codeforces.com/blog/entry/61993
