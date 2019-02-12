//Header Files
# include <bits/stdc++.h>
# include <algorithm>

using namespace std;

int main(void) //Driver Function
{
    int n, k, Ans = 0;
    cin >> n >> k;
    pair <int, int> Teams[n];
      for(int i = 0 ; i < n ; i++)
        {
            cin >> Teams[i].first >> Teams[i].second;
            Teams[i].first *= -1; //Multiplying by -1 because the number of problems solved are to be sorted in descending
            //order.
        }
    sort(Teams, Teams + n);
      for(int i = 0 ; i < n ; i++)
        {
            if(Teams[i] == Teams[k - 1]) //-1 is used on the RHS of the expression as the pair is zero-indexed.
              {
                  Ans++;
              }
        }
    cout << Ans << endl;
    return 0;
}
//End Of Program
