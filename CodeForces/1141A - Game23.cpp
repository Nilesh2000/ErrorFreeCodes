//Header Files
# include <bits/stdc++.h>

# define pb push_back

using namespace std;

int main(void) //Driver Function
{
  ios_base::sync_with_stdio(false);
  int a, b;
  cin >> a >> b;
    if(b % a)
      {
        cout << -1 << endl;
        return 0;
      }
  b /= a;
  int Count = 0;
    while(b % 2 == 0)
      b /=2, Count++; //Can add two statements separated by commas inside a while loop
    while(b % 3 == 0)
      b/=3, Count++;
    if(b != 1) 
      {
          cout << -1 << endl;
          return 0;
      }
  cout << Count << endl;
  return 0;
}
//End Of Program
