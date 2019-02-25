//Header Files
# include <bits/stdc++.h>

# define pb push_back

using namespace std;

int main(void) //Driver Function
{
  ios_base::sync_with_stdio(false);
  int k, a = 0, b = 0, n;
  cin >> n;
    for(int i = 0 ; i < n ; i++)
      {
          cin >> k;
            if(k > 0) //Count number of positve elements.
              {
                  a++;
              }
            else if(k < 0) //Count number of negative elements.
              {
                  b++;
              }
      }
  //We can't use the ceil function here becuase n/2 will return an integer and not a floating point constant.
  //For example, 5/2 = 2 and not 2.5 .
    if(a * 2 >= n)
      {
          cout << 1 << endl;
      }
    else if(b * 2 >= n)
      {
          cout << -1 << endl;
      }
    else
      {
          cout << 0 << endl;
      }
  return 0;
}

/*
If there are at least ⌈n/2⌉ positive elements in a, then 1 is one answer.
Similarly, if there are at least ⌈n/2⌉ negative elements in a, then −1 is one answer.
Otherwise, there is no answer. (Answer will be 0)
The time complexity is O(n).

End Of Program
*/
