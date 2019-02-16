//Header Files
# include <bits/stdc++.h>

# define pb push_back

using namespace std;

int main(void) //Driver Function
{
  ios_base::sync_with_stdio(false);
  string s, Card;
  cin >> s;
  int numOfCards = 5;
    while(numOfCards--)
      {
        cin >> Card;
          if(s[0] == Card[0] || s[1] == Card[1])
            {
                cout << "YES" << endl;
                return 0;
            }
      }
  cout << "NO" << endl;
  //return 0;
}
//End Of Program
